#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Node{
	int cost, x, y;
	Node(int a, int b, int c) {
		cost = a; x = b; y = c;
	}
	bool operator<(const Node &k) const {
		return cost > k.cost;
	}
};

int Map[301][301], dp[301][301], dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int n, m, ans;
priority_queue<Node> pq;

int main(void) {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			scanf("%d", &Map[i][j]);
			if (!i || !j || i == n - 1 || j == m - 1)
				pq.push(Node(Map[i][j], i, j));
		}
	memset(dp, -1, sizeof dp);
	while (!pq.empty()) {
		int x = pq.top().x, y = pq.top().y, cost = pq.top().cost; pq.pop();
		if (dp[x][y] != -1) continue;
		dp[x][y] = cost;
		ans += dp[x][y] - Map[x][y];
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1)continue;
			pq.push(Node(max(cost, Map[nx][ny]), nx, ny));
		}
	}
	printf("%d\n", ans);
	return 0;
}