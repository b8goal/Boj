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
using namespace std;

const int INF = 987654321;
const int MOD = 998244353;
const int MAXN = 1001;

pair<int,int>  a[50001], b[50001];
int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		a[i].second = b[i].second = i;
		scanf("%d %d", &a[i].first, &b[i].first);
	}
	sort(a, a + n,greater<pair<int,int> >());
	vector<pair<int, int> > v;
	for (int i = 0; i < k; i++) {
		v.push_back({ b[a[i].second].first, a[i].second});
	}
	sort(v.begin(), v.end(),greater<pair<int,int> >());
	printf("%d\n", v[0].second+1);
}