#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

using pii = pair<int, int>;

int main() {
	int A, B, ans = 1; scanf("%d%d", &A, &B);
	set<long long> chk;
	queue<long long> que; que.push(A);
	while (que.size()) {
		int sz = que.size();
		while (sz--) {
			long long now = que.front(); que.pop();
			if (now > 1e9) continue;
			if (now == 1LL * B) return !printf("%d", ans);
			long long n1 = now * 2, n2 = now * 10 + 1;
			if (chk.find(n1) == chk.end()) {
				chk.insert(n1);
				que.push(n1);
			}
			if (chk.find(n2) == chk.end()) {
				chk.insert(n2);
				que.push(n2);
			}
		}
		++ans;
	}
	puts("-1");
	return 0;
}