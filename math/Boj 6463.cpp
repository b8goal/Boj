#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
#define MOD 360000
using namespace std;

int main(void) {
	long long n, k;
	while (scanf("%lld", &n)!=EOF) {
		k = 1;
		for (int i = 1; i <= n; ++i) {
			//printf("%d %d\n",i, k);
			k *= i;
			while (!(k % 10))
				k /= 10;
			k %= 100000;
		}
		printf("%5lld -> %lld\n", n, k%10);
	}
	return 0;
}