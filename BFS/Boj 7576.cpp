#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int Map[1001][1001], R, C, time;
int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
queue<pair<int, int> > q;

void bfs(void)
{
	while (!q.empty())
	{
		int len = q.size();
		for (int l = 0; l < len; l++)
		{
			pair<int, int> cur = q.front(); q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = cur.first + dx[i], ny = cur.second + dy[i];
				if (nx < 0 || nx >= R || ny < 0 || ny >= C || Map[nx][ny] ==-1)continue;
				if (Map[nx][ny] == 0)
				{
					Map[nx][ny] = Map[cur.first][cur.second];
					q.push({ nx,ny });
				}
			}
		}
		time++;
	}
}
int main(void)
{
	scanf("%d %d", &C, &R);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf("%d", &Map[i][j]);
			if (Map[i][j] == 1)
			{
				q.push({ i,j });
			}
		}
	}
	bfs();
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (Map[i][j] == 0)
			{
				printf("%d\n", -1);
				return 0;
			}
	printf("%d\n", time-1);
	return 0;
	
}