#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a[101][101], dx[] = { 1,0,-1,0 }, dy[] = { 0,-1,0, 1 };

int main(void) {
	int n, sx, sy, cx, cy, ex, ey, d;
	string s;
	cin >> n >> s;
	cx = cy = ex = ey = sx = sy = 50;
	a[cx][cy] = 1;
	d = 0;
	for (int i = 0; s[i]; i++) {
		if (s[i] == 'R') d = (d + 1) % 4;
		else if (s[i] == 'L') d = (d + 3) % 4;
		else {
			cx += dx[d]; cy += dy[d];
			a[cx][cy] = 1;
			if (cx < sx)sx = cx;
			if (cy < sy)sy = cy;
			if (cx > ex)ex = cx;
			if (cy > ey)ey = cy;
		}
	}

	for (int i = sx; i <= ex; i++){
		for (int j = sy; j <= ey; j++){
			if (a[i][j])
				cout << '.';
			else
				cout << '#';
		}puts("");
	}
	return 0;
}