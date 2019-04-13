#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
	int x, y, d;
	Node(int x1, int y1, int d1) {
		x = x1; y = y1; d = d1;
	};
};
char b[10001];
int a[100][100], dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int n, k, l, t;
int main(void) {
	cin >> n >> k;
	while(k--) {
		int x, y;
		cin >> x >> y;
		a[x - 1][y - 1] = 1;
	}
	cin >> l;
	while (l--) {
		int x; char y;
		cin >> x >> y;
		b[x+1] = y;
	}
	deque<Node> q;
	q.push_back(Node(0, 0, 0));
	a[0][0] = 2;
	while (++t) {
		Node p = q.front();
		p.d = (b[t] == 'D' ? (p.d + 1) % 4 : b[t] == 'L' ? (p.d + 3) % 4 : p.d);
		int nx = p.x + dx[p.d], ny = p.y + dy[p.d];
		if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1 || a[nx][ny] == 2) break;
		if (a[nx][ny]) {
			a[nx][ny] = 2;
			q.push_front(Node(nx, ny, p.d));
		}
		else{
			a[nx][ny] = 2;
			q.push_front(Node(nx, ny, p.d));
			Node p = q.back(); q.pop_back();
			a[p.x][p.y] = 0;
			
		}
	}
	cout << t << '\n';
	return 0;
}