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
#include <cmath>
#include <map>
#include <stack>
#define C 10
using namespace std;

typedef long long ll;
const int INF = 100000000;
const int MOD = 1000000007;
const int MAXN = 4000;

int main(void) {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int x;
		scanf("%d", &x);
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < x; j++) {
				if (i == 0 || i == x - 1) {
					printf("#");
				}
				else {
					if (j == 0 || j == x - 1)
						printf("#");
					else
						printf("J");
				}
			}
			puts("");
		}
		puts("");
	}
	return 0;
}