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
#include <deque>
#define C 10
using namespace std;

typedef long long ll;
const int INF = 987654321;
const int MOD = 1000000007;
const int MAXN = 101;

int main(void) {
	int x, sum, tc;
	cin >> tc;
	getchar();
	while (tc--) {
		sum = 0;
		x = 0;
		string  s;
		getline(cin, s);
		for (int i = 0; s[i]; i++) {
			if (s[i] == ' ') {
				sum += x;
				x = 0;
			}
			else
				x = x * 10 + s[i] - '0';
		}
		printf("%d\n", sum+x);
	}
	return 0;
}