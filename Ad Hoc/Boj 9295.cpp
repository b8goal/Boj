#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int tc, t, x, y;
int main(void) {
	cin >> tc;
	while(tc--) {
		t++;
		cin >> x >> y;
		cout << "Case " << t << ": " << x + y << '\n';
	}
	return 0;
}