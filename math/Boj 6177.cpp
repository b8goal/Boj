#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

int a[500];
int n, sum;

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sort(a, a + n);
	double ans = (double) sum / n;
	printf("%lf\n", ans);
	printf("%lf\n", n % 2 ? a[n / 2] : (double)(a[n / 2-1] + a[n / 2]) / 2);
	return 0;
}