#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
#define MOD 360000
using namespace std;

int k[1001];
bool chk[1001];
int main(void) {
	int n, m, s;
	s = 0;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
		cin >> k[i];
	for (int i = 0; i < m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (!chk[j] && j%k[i] == 0){
				chk[j] = 1;
				s += j;
			}
		}
	}
	cout << s << '\n';
	return 0;
}