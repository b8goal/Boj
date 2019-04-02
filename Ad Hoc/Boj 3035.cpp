#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

char a[55][55];
int main(void) {
	int r, c, zr, zc;
	cin >> r >> c >> zr >> zc;
	for (int i = 0; i < r; i++)
		cin >> a[i];

	for (int i = 0; i < r; i++) {
		for (int x = 0; x < zr; x++) {
			for (int j = 0; j < c; j++) {
				for (int y = 0; y < zc; y++) {
					cout << a[i][j];
				}
			}
			cout << '\n';
		}
	}
	return 0;
}