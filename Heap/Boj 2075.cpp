#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#define C 10
using namespace std;

typedef long long ll;
const int INF = 100000000;
const int MOD = 1000000007;
const int MAXN = 4000;

int abs(int x) { return x > 0 ? x : -x; }
int a[1500][1500];
int main(void) {
	int n;
	priority_queue<int, vector<int>, greater<int>> pq;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			pq.push(a[j][i]);
			if (pq.size() > n)
				pq.pop();
		}
	printf("%d\n", pq.top());
	return 0;
}