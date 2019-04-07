#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main(void) {
	int n, a, b;
	cin >> n;
	a = b = 0;
	for (int i = 0; i < n; i++) {
		char x;
		cin >> x;
		x == 'A' ? a++ : b++;
	}
	if (a == b)
		cout << "Tie" << '\n';
	else if (a > b)
		cout << "A" << '\n';
	else
		cout << "B" << '\n';
	return 0;
}