#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <functional>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <math.h>

#define C 10
using namespace std;

const int INF = 1000000000;
const int MOD = 998244353;
const int MAXN = 100000;

int p[MAXN + 1], cnt[MAXN + 1];
vector<int> pr;

int main(void) {

	for (int i = 2; i <= MAXN; i++) {
		if (!p[i]) {
			p[i] = 1;
			pr.push_back(i);
			for (int j = 2 * i; j <= MAXN; j += i) {
				p[j] = -1;
			}
		}
	}
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, len;
		scanf("%d", &n);
		len = n;
		memset(cnt, 0, sizeof cnt);
		while (n>=2) {
			for (int i = 0; i < pr.size(); i++) {
				if (n%pr[i] == 0)
				{
					cnt[pr[i]]++;
					n /= pr[i];
				}
			}
		}
		for (int i = 0; i < pr.size(); i++) {
			if(cnt[pr[i]])
			printf("%d %d\n", pr[i], cnt[pr[i]]);
		}
	}
	return 0;
}