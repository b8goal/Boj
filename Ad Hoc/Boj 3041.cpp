#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

char a[4][4], b[4][4];
int main(void) {
	int cnt = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			a[i][j] = 'A' + i * 4 + j;
	a[4][4] = '.';
	
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> b[i][j];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					if (a[i][j] == b[k][l] && a[i][j] != '.')
						cnt += abs(i - k) + abs(j - l);
				}
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}