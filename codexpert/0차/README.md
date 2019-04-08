1. 원안의 사각형
```
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int chk[2001][2001];
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int main(void){
	int r, cnt;
	cin >> r;
	
	cnt = 0;
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(1000, 1000), 1));
	chk[1000][1000] = 1;
	while (!q.empty()) {
		pair<pair<int, int>, int> p = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = p.first.first + dx[i], ny = p.first.second + dy[i];
			if (nx < 1000 - r || nx>1000 + r || ny < 1000 - r || ny>1000 + r || sqrt((nx-1000)*(nx - 1000) +(ny-1000)*(ny - 1000))>r || chk[nx][ny]) continue;
			chk[nx][ny] = 1;
			q.push(make_pair(make_pair(nx, ny), 1));
		}
	}

	for (int i = 0; i < 2000; i++)
		for (int j = 0; j < 2000; j++)
			if (chk[i][j] && chk[i + 1][j] && chk[i][j + 1] && chk[i + 1][j + 1])
				cnt++;
	cout << cnt << '\n';
	return 0;
}
```

2. 비행기 게임
```
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

char a[13][5], b[13][5], dx[] = { -1,-1,-1 }, dy[] = { -1,0, 1 };
int mx, cnt;
void f(int x, int y,int bomb, int score) {
	if (x < 0 || y < 0 || y>4) return;
	if (x == 0) {
		mx = max(mx, score);
		if (mx == cnt * 10) {
			cout << mx << '\n';
			exit(0);
		}
		return;
	}

	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (b[nx][ny] == '0')
			f(nx, ny, bomb, score);
		if (b[nx][ny] == '*')
			f(nx, ny, bomb, score + 10);
		if (b[nx][ny] == 'X') {
			if (bomb) {
				for (int j = 1; j <= 5 && x - j >= 0; j++)
					for (int k = 0; k < 5; k++)
						if (b[x - j][k] == 'X')
							b[x - j][k] = '0';
				f(nx, ny, 0, score);
				for (int j = 0; j < 13; j++) {
					for (int k = 0; k < 5; k++) {
						b[j][k] = a[j][k];
					}
				}
			}
			f(nx, ny, bomb, score - 7);
		}
	}
}
int main(void) {
	int tc;
	cin >> tc;
	while (tc--) {
		for (int i = 0; i < 13; i++){
			for (int j = 0; j < 5; j++){
				cin >> a[i][j];
				b[i][j] = a[i][j];
				if (a[i][j] == '*')
					cnt++;
			}
		}
		mx = -0x7fffffff;
		f(12, 2, 1, 0);
		cout << mx << '\n';
	}
	return 0;
}
```