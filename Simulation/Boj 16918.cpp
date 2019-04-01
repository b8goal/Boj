#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

char a[205][205];
int Map[205][205], chk[205][205], dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };
int main(void) {
	int r, c, n;
	cin >> r >> c >> n;
	for (int i = 0; i < r; i++){
		cin >> a[i];
		for (int j = 0; j < c; j++) 
			if (a[i][j] == 'O')
				Map[i][j] = 2;
	}

	for (int l = 1; l < n; l++) {
		for (int i = 0; i < r; i++) 
			for (int j = 0; j < c; j++) 
					Map[i][j]++;

		if (l == n) break;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (Map[i][j] == 4){
					Map[i][j] = 0;
					for (int k = 0; k < 4; k++) {
						int ny = i + dy[k], nx = j + dx[k];
						if (ny<0 || ny>r - 1 || nx<0 || nx>c - 1 || Map[ny][nx]==4) continue;
						Map[ny][nx] = 0;
					}
				}
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!Map[i][j])
				cout << '.';
			else
				cout << 'O';
		}puts("");
	}
	
	
	return 0;
}