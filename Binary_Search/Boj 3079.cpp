#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

using namespace std;
const long long MAX_N = 1000000000000000000LL;
int n, m;
long long ret, input;
vector<long long> vt;

void solve(long long s, long long e) {
	if (s > e) return;
	long long mid = (s + e) / 2, sum = 0;
	for (int i = 0; i < n; i++)
		sum += mid / vt[i];
	if (sum >= m) {
		ret = min(ret, mid);
		solve(s, mid - 1);
	}
	else solve(mid + 1, e);
}
int main(void)
{
	int tc;
	long long mx = -1;
	vt.clear();
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input);
		vt.push_back(input);
		if (mx < input)
			mx = input;
	}
	ret = MAX_N;
	solve(0, MAX_N);
	printf("%lld", ret);


	return 0;
}