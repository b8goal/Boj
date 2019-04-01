#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

char Map[30][30];
int R, C;
int left(int r, int c) {
	return c - 1 > 0 && (Map[r][c - 1] == '+' || Map[r][c - 1] == '-' || Map[r][c - 1] == '1' || Map[r][c - 1] == '2');
}
int right(int r, int c) {
	return c + 1 < C && (Map[r][c + 1] == '+' || Map[r][c + 1] == '-' || Map[r][c + 1] == '3' || Map[r][c + 1] == '4');
}
int up(int r, int c) {
	return  r - 1 > 0 && (Map[r - 1][c] == '+' || Map[r - 1][c] == '|' || Map[r - 1][c] == '1' || Map[r - 1][c] == '4');
}
int down(int r, int c) {
	return  r + 1 < R && (Map[r + 1][c] == '+' || Map[r + 1][c] == '|' || Map[r + 1][c] == '2' || Map[r + 1][c] == '3');
}
int main(void) {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> Map[i];
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (Map[i][j] != '.') continue;
			if (left(i, j) && right(i, j) && down(i, j) && up(i, j)) cout << i + 1 << ' ' << j + 1 << " +";
			else if (up(i, j) && down(i, j)) cout << i + 1 << ' ' << j + 1 << " |";
			else if (left(i, j) && right(i, j)) cout << i + 1 << ' ' << j + 1 << " -";
			else if (down(i, j) && right(i, j)) cout << i + 1 << ' ' << j + 1 << " 1";
			else if (up(i, j) && right(i, j)) cout << i + 1 << ' ' << j + 1 << " 2";
			else if (up(i, j) && left(i, j)) cout << i + 1 << ' ' << j + 1 << " 3";
			else if (left(i, j) && down(i, j)) cout << i + 1 << ' ' << j + 1 << " 4";

		}
	}
	return 0;
}