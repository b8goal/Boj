#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main(void) {
	int n;
	cin >> n;
	while (n--) {
		int a[10];
		for (int i = 0; i < 10; i++)
			cin >> a[i];
		sort(a, a + 10);
		cout << a[7] << '\n';
	}
	return 0;
}