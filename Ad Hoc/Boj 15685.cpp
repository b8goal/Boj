#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <math.h>

using namespace std;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,-1,0,1 };
bool Map[105][105];
vector<int> v;

int main(void) {
	int n;
	scanf("%d", &n);
	while (n--) {
		v.clear();
		int x, y, d, g;
		scanf("%d %d %d %d", &x, &y, &d, &g);
		v.push_back(d);
		for (int i = 0; i < g; i++) {
			int len = v.size();
			for (int j = len-1; j >= 0; j--) {
				v.push_back((v[j] + 1) % 4);
			}
		}
		Map[y][x] = 1;
		for (int i = 0; i < v.size(); i++) {
			y += dy[v[i]]; x += dx[v[i]];
			Map[y][x] = 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (Map[i][j] && Map[i + 1][j] && Map[i][j + 1] && Map[i + 1][j + 1])
				ans++;
	printf("%d\n", ans);
	return 0;
}