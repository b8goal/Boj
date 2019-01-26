#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MOD = 9901;
const int INF = 0x7fffffff;
const int MAXN = 300;

int main(void) {
	int tc;
	long long a, b;
	scanf("%d", &tc);
	for(int t=1; t<=tc; ++t){
		scanf("%lld %lld", &a, &b);
		printf("Scenario #%d:\n%lld\n\n", t,(b + a)*(b - a + 1) / 2);
	}
	return 0;
}