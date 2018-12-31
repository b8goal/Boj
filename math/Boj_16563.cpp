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
const int MAXN = 5000000;

int p[MAXN + 1];
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

	int n;
	scanf("%d", &n);
	for (int i = 0,x; i < n; i++) {
		scanf("%d", &x);
		if (p[x] == 1) {
			printf("%d\n", x);
		}
		else {
			while (x>=2) {
				for (int i = 0; i < pr.size(); i++) {
					if (p[x] == 1) {
						printf("%d", x);
						x = 1;
						break;
					}
					else if (x%pr[i] == 0) {
						printf("%d ", pr[i]);
						x /= pr[i];
						break;
					}
				}
			}
			puts("");
		}
	}
	return 0;
}