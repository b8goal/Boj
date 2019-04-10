#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int a[15][15], chk[15][15], b[6];
int mn;

int poss(int x, int y, int num) {
	int cnt = 0;
	for (int i = x; i < x + num; i++)
		for (int j = y; j < y + num; j++)
			if (a[i][j])
				cnt++;
	return cnt == num*num ? 1 : 0;
}

void update(int x, int y, int num, int flag) {
	for (int i = x; i < x + num; i++)
		for (int j = y; j < y + num; j++)
			a[i][j] = flag;
}
void f(int x, int y,int cnt) {
	int flag = 0;
	for (int i = x; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (a[i][j]){
				x = i;
				y = j;
				flag++;
				break;
			}
		}
		if (flag)break;
	}
	if (!flag) {
		mn = min(mn, cnt);
		return;
	}
	//cout << x << ' ' << y << ' ' << cnt << '\n';
	for (int i = 5; i >= 1; i--) {
		if (b[i] + 1 <= 5 && poss(x, y, i)) {
			b[i]++;
			update(x, y, i, 0);
			f(x, y , cnt + 1);
			b[i]--;
			update(x, y, i, 1);
		}
	}
}

int main(void) {
	int cnt = 0;
	mn = 987654321;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++){
			cin >> a[i][j];
			if (a[i][j])
				cnt++;
		}
	if (!cnt)
		puts("0");
	else {
		f(0, 0, 0);
		if (mn == 987654321)
			cout << -1 << '\n';
		else
			cout << mn << '\n';
	}
	return 0;
}