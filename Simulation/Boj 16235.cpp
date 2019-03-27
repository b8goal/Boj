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

int dx[8] = { -1,-1,-1,0,0,1,1,1 }, dy[8] = { -1,0,1,-1,1,-1,0,1 }, A[15][15], B[15][15], C[15][15];
vector<int> tree[11 * 11];

// A는 겨울에 쓰일 양분
// B는 현재 양분
int main(void) {
	int n, m, k, cnt;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++){
			scanf("%d", &A[i][j]);
			B[i][j] = 5;
		}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		x--; y--;
		tree[n*x + y].push_back(z); // x,y는 나무의 위치, z는 나무의 나이
	}
	
	cnt = 0;
	for(int len=0; len<k; len++) {
		for (int i = 0; i < n * n; i++)
			sort(tree[i].begin(), tree[i].end());

		for (int i = 0; i < n * n; i++) { // 봄
			int cnt = 0;
			for (int j = 0; j < tree[i].size(); j++) {
				if (B[i / n][i%n] >= tree[i][j]) {
					B[i / n][i%n] -= tree[i][j]; // 나무의 나이만큼 양분 먹고
					tree[i][j]++; // 나무 나이 증가
				}
				else {
					cnt = tree[i].size() - j;
					break;
				}
			}
			for (int j = 0; j < cnt; j++) {
				if (tree[i].size() == 0)
					break;
				C[i / n][i%n] += tree[i].back() / 2; // 죽은 나무
				tree[i].erase(tree[i].begin()+tree[i].size()-1);
			}
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				B[i][j] += C[i][j];
				C[i][j] = 0;
			}
		
		vector<int> tree2[11 * 11];
		for (int i = 0; i < n*n; i++) {
			for (int j = 0; j < tree[i].size(); j++) {
				if (tree[i][j] >=5 && tree[i][j] % 5 == 0) {
					int x = i / n, y = i % n;
					for (int k = 0; k < 8; k++) {
						int nx = x + dx[k], ny = y + dy[k];
						if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1) continue;
						tree2[nx*n+ny].push_back(1);
					}
				}
			}
		}
		for (int i = 0; i < n*n; i++)
			for (int j = 0; j < tree2[i].size(); j++)
				tree[i].push_back(tree2[i][j]);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				B[i][j] += A[i][j];
	}
	for (int i = 0; i < n*n; i++)
		cnt += tree[i].size();
	printf("%d\n", cnt);
	return 0;
}