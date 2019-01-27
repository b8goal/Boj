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

int cache[100001], chk[9], arr[9];
int n, m; 
void dfs(int k) {
	if (k == m) {
		for (int i = 0; i < k; i++)
			printf("%d ", arr[i]);
		puts("");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!chk[i]) {
			chk[i] = 1;
			arr[k] = i;
			dfs(k + 1);
			chk[i] = 0;
		}
	}
}
int main(void) {
	scanf("%d %d", &n, &m);
	dfs(0);
	return 0;
}