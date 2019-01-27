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

int main(void) {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, flag = 0;
		scanf("%d", &n);
		printf("Pairs for %d: ", n);
		for (int i = 1; i <= 12; i++) {
			for (int j = 12; j > i; j--) {
				if (i + j == n && !flag) {
					flag = 1;
					printf("%d %d", i, j);
				}
				else if (i + j == n && flag)
					printf(", %d %d", i, j);
			}
		}
		puts("");
	}
	return 0;
}