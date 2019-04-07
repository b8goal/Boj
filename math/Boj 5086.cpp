#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main(void) {
	while (1) {
		int a, b;
		cin >> a >> b;
		if (!(a + b))
			break;
		if (!(b%a))
			cout << "factor" << '\n';
		else if (!(a%b))
			cout << "multiple" << '\n';
		else
			cout << "neither" << '\n';
	}
	return 0;
}