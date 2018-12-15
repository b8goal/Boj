#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <functional>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

const int INF = 0x7fffffff;
const int MAXN = 52;

int n, ans;
int c[MAXN][MAXN], f[MAXN][MAXN];
vector<int> v[MAXN];

int cal(char x) {
	if (x <= 'Z') return x - 'A';
	return x - 'a' + 26;
}

void max_flow(int start, int end) {
	while (1) {
		int prev[MAXN];
		fill(prev, prev + MAXN, -1);
		queue<int> q;
		q.push(start);
		while (!q.empty() && prev[end] == -1) {
			int cur = q.front(); q.pop();
			for (auto next : v[cur]) {
				if (c[cur][next] - f[cur][next] > 0 && prev[next] == -1) {
					prev[next] = cur;
					q.push(next);
					if (next == end) break;
				}
			}
		}
		if (prev[end] == -1) break;
		int flow = INF;
		for (int i = end; i != start; i = prev[i])
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		for (int i = end; i != start; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		ans += flow;
	}
}

int main(void) {
	char x, y;
	int z;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c %c %d", &x, &y, &z);
		x = cal(x); y = cal(y);
		c[x][y] = c[y][x] += z;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	max_flow(cal('A'), cal('Z'));
	printf("%d\n", ans);
	return 0;
}