#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

bool check[26][26];
int Map[1001][1001], R, C, time;
int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
vector<int> vt;
queue<pair<int, int> > q;

void bfs(void)
{
	int cnt = 0;
	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
		check[cur.first][cur.second] = 1;
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i], ny = cur.second + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= R)continue;
			if (Map[nx][ny] == 1 && !check[nx][ny])
			{
				check[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
		cnt++;
	}
	vt.push_back(cnt);
	
}
int main(void)
{
	int ans = 0;
	scanf("%d", &R);
	for (int i = 0; i < R; i++)
		for (int j = 0; j < R; j++)
			scanf("%1d", &Map[i][j]);

	for(int i=0 ;i<R; i++)
		for(int j=0; j<R; j++)
			if (Map[i][j] && !check[i][j]) 
			{
				q.push({ i,j });
				bfs();
				ans++;
			}
	printf("%d\n", ans);
	sort(vt.begin(), vt.end());
	for (int i = 0; i < vt.size(); i++)
		printf("%d\n", vt[i]);
	return 0;
	
}