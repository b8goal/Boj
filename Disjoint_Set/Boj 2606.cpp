#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
typedef long long ll;
using namespace std;
const int MOD = 9901;
const int INF = 0x7fffffff;
const int MAXN = 300;
int p[101];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
int main(void) {
	int n, m, cnt = 0;
	for (int i = 0; i < 101; i++) p[i] = i;
	scanf("%d %d", &n, &m);
	for (int i = 0,x,y; i < m; i++) {
		scanf("%d %d", &x, &y);
		if (find(x) != find(y))
			p[find(x)] = find(y);
	}
	for (int i = 2; i < 101; i++)
		cnt += find(1) == find(i);
	printf("%d\n", cnt);
	return 0;
}