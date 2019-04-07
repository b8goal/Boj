#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main(void) {
	int tc;
	cin >> tc;
	while (tc--) {
		int a[5];
		for (int i = 0; i < 5; i++)
			cin >> a[i];
		sort(a, a + 5);
		if (a[3] - a[1] >= 4)
			cout << "KIN" << '\n';
		else
			cout << a[1] + a[2] + a[3] << '\n';
	}
	return 0;
}