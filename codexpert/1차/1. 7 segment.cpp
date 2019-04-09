#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
int a[12][7], c[6];
int mn;

int poss(int x, int y) {
	if (y == 0 && !a[x][6]) return 1;
	if (y == 1 && !a[x][0] && !a[x][1] && !a[x][4] && !a[x][5] && !a[x][6]) return 1;
	if (y == 2 && !a[x][0] && !a[x][3]) return 1;
	if (y == 3 && !a[x][0] && !a[x][5]) return 1;
	if (y == 4 && !a[x][1] && !a[x][4] && !a[x][5]) return 1;
	if (y == 5 && !a[x][2] && !a[x][5]) return 1;
	if (y == 6 && !a[x][2]) return 1;
	if (y == 7 && !a[x][0] && !a[x][4] && !a[x][5] && !a[x][6]) return 1;
	if (y == 8) return 1;
	if (y == 9 && !a[x][5]) return 1;
	return 0;
}

void f(int num) {
	if (num == 6) {
		int temp = ((100 * c[0] + 10 * c[1] + c[2])*(100 * c[3] + 10 * c[4] + c[5]));
		int cnt, tmp;
		cnt = 0;
		tmp = temp;
		for (int i = 0; i < 6; i++) {
			if (poss(11 - i, tmp % 10) && c[i] != -1) {
				tmp /= 10;
				cnt++;
			}
		}
		if (cnt == 6)
			mn = min(mn, temp);
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (poss(num, i)) {
			c[num] = i;
			f(num + 1);
			c[num] = -1;
		}
	}
}
int main(void) {
	memset(c, -1, sizeof - 1);
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 7; j++) {
			scanf("%1d", &a[i][j]);
		}
	mn = 999 * 999;
	f(0);
	printf("%d\n", mn);
	return 0;
}