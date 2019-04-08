#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main(void) {
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		cout << s[0] << s.back() << '\n';
	}
	return 0;
}