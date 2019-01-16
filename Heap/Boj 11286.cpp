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

int abs(int x) { return x > 0 ? x : -x; }
int main(void) {
	priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> >> pq;
	int n, x;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		if (!x) {
			if (pq.empty())
				puts("0");
			else {
				printf("%d\n", pq.top().second);
				pq.pop();
			}
		}
		else {
			pq.push(make_pair(abs(x), x));
		}
	}
	return 0;
}