#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
typedef long long ll;
using namespace std;
const int MOD = 1000000;
const int INF = 0x7fffffff;
const int MAXN = 300;
int p[1000001], dp[1001][1001], Map[201][201];
ll cache[61][61];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }
int n, m, cnt;
vector<int> v;
void go(int k) {
	if (v.size() == 3) {
		for(int i=0; i<v.size(); i++)
			for (int j = i + 1; j < v.size(); j++) {
				if (Map[v[i]][v[j]])
					return;
			}
		cnt++;
		return;
	}
	for (int i = k; i <= n; i++) {
		v.push_back(i);
		go(i + 1);
		v.pop_back();
	}
}
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0,x,y; i < m; i++) {
		scanf("%d %d", &x, &y);
		Map[x][y] = Map[y][x] = 1;
	}
	go(1);
	printf("%d\n", cnt);
}