#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main(void) {
	string s;
	int n;
	cin >> n;
	while (n--) {
		double x;
		cin >> x;
		getline(cin, s);
		for (int i = 0; s[i]; i++) {
			if ('0' <= s[i] && s[i] <= '9') 
				x = s[i] - '0';
			if (s[i] == '@')
				x *= 3.0;
			if (s[i] == '%')
				x += 5.0;
			if (s[i] == '#')
				x -= 7.0;
		}
		cout << fixed;
		cout.precision(2);
		cout <<showpoint<< x << '\n';
	}
	return 0;
}