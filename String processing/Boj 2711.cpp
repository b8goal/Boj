#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main(void) {
	int n,x;
	cin >> n;
	while (n--) {
		cin >> x;
		string s;
		cin >> s;
		for (int i = 0; s[i]; i++) {
			if (i == x - 1)
				continue;
			else
				cout << s[i];
		}
		cout << '\n';
	}
	return 0;
}