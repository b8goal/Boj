#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main(void) {
	int tc, x, y;
	cin >> tc;
	while (tc--) {
		cin >> x >> y;
		cout << "You get " << x / y <<" piece(s) and your dad gets "<<x%y<<" piece(s)." << '\n';
	}
	return 0;
}