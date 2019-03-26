#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <bitset>
#include <random>
#include <ctime>
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define REP(i,n) FOR(i,0,n)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
const int MOD = 10007;
const int INF = 0x7fffffff;
const int MIN = -32768 * 101;
const int MAXN = 100000 + 1;
const long double PI = 3.141592653589793238462643383279502884197;
int p[100];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y%x ? gcd(y, x%y) : x; }

char Map[55][55];
bool chk[2][55][55];
int n;
int sx[3], sy[3], ex[3], ey[3], dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
struct Node {
	int x[3], y[3], state, cnt;
	Node(int a[], int b[],int state1, int cnt1) {
		x[0] = a[0], x[1] = a[1]; x[2] = a[2];
		y[0] = b[0], y[1] = b[1]; y[2] = b[2];
		state = state1; cnt = cnt1;
	}
};

int is_range(Node p,int dir) {
	for (int i = 0; i < 3; i++) 
		if (Map[p.x[i]+dx[dir]][p.y[i]+dy[dir]] =='1' || p.x[i] + dx[dir] <0 || p.x[i] + dx[dir]>n - 1 || p.y[i] + dy[dir] < 0 || p.y[i] + dy[dir] > n - 1 || chk[p.state][p.x[1]+dx[dir]][p.y[1]+dy[dir]])
			return 0;
	return 1;
}

int is_range1(Node p) {
	if (p.state == 0) { // 가로
		if (p.x[0] == 0 || p.x[0] == n - 1 || chk[1][p.x[1]][p.y[1]]) return 0;
		for (int i = 0; i < 3; i++) {
			if (Map[p.x[i] - 1][p.y[i]] == '1') return 0;
			if (Map[p.x[i] + 1][p.y[i]] == '1') return 0;
		}
	}
	else {
		if (p.y[0] == 0 || p.y[0] == n - 1 || chk[0][p.x[1]][p.y[1]]) return 0;
		for (int i = 0; i < 3; i++) {
			if (Map[p.x[i]][p.y[i]-1] == '1') return 0;
			if (Map[p.x[i]][p.y[i]+1] == '1') return 0;
		}
	}
	return 1;
}

int main(void) {
	scanf("%d", &n);
	memset(sx, -1, sizeof sx);
	memset(sy, -1, sizeof sy);
	memset(ex, -1, sizeof ex);
	memset(ey, -1, sizeof ey);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %c", &Map[i][j]);
			if (Map[i][j] == 'B')
				for (int k = 0; k < 3; k++) {
					if (sx[k] == -1) {
						sx[k] = i; sy[k] = j;
						break;
					}
				}
			if(Map[i][j] == 'E')
				for (int k = 0; k < 3; k++) {
					if (ex[k] == -1) {
						ex[k] = i; ey[k] = j;
						break;
					}
				}
		}
	}
	queue<Node> q;
	if (sx[0] == sx[1]){
		chk[0][sx[1]][sy[1]] = true; // 0 가로
		q.push(Node(sx, sy, 0, 0));
	}
	else{
		chk[1][sx[1]][sy[1]] = true;
		q.push(Node(sx, sy, 1, 0));
	}
	while (!q.empty()) {
		Node p = q.front(); q.pop();

		//printf("state = %d\n", p.state);
		//for (int k = 0; k < 3; k++) {
		//	printf("%d %d\n", p.x[k], p.y[k]);
		//}


		if (p.x[0] == ex[0] && p.y[0] == ey[0] && p.x[1] == ex[1] && p.y[1] == ey[1] && p.x[2] == ex[2] && p.y[2] == ey[2]) {
			printf("%d\n", p.cnt);
			return 0;
		}
		for (int i = 0; i < 4; i++) 
			if (is_range(p, i)) {
				chk[p.state][p.x[1] + dx[i]][p.y[1] + dy[i]] = true;
				int nx[3], ny[3];
				for (int j = 0; j < 3; j++)
					nx[j] = p.x[j] + dx[i], ny[j] = p.y[j] + dy[i];
				q.push(Node(nx, ny, p.state, p.cnt + 1));
			}
		if (is_range1(p)) {
			if (p.state == 0) {
				chk[1][p.x[1]][p.y[1]] = true;
				int nx[3], ny[3];
				nx[0] = p.x[1] - 1; ny[0] = p.y[1];
				nx[1] = p.x[1]; ny[1] = p.y[1];
				nx[2] = p.x[1] + 1; ny[2] = p.y[1];
				q.push(Node(nx, ny, 1, p.cnt + 1));
			}

			if (p.state == 1) {
				chk[0][p.x[1]][p.y[1]] = true;
				int nx[3], ny[3];
				nx[0] = p.x[1]; ny[0] = p.y[1]-1;
				nx[1] = p.x[1]; ny[1] = p.y[1];
				nx[2] = p.x[1]; ny[2] = p.y[1]+1;
				q.push(Node(nx, ny, 0, p.cnt + 1));
			}
		}

	}
	puts("0");
	return 0;
}