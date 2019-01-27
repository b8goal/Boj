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

int arr[9];
int n, m, cnt;

void dfs(int k) {
	if (cnt == m) {
		for (int i = 0; i < m; ++i)
			cout << arr[i] << ' ';
		puts("");
		return;
	}
	for (int i = k; i <= n; i++) {
		if (cnt < m) {
			arr[cnt++] = i;
			dfs(i + 1);
			arr[cnt--] = 0;
		}
	}
}
int main(void) {
	cin >> n >> m;
	dfs(1);
	return 0;
}