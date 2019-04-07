#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i % 2)
			for (int j = 0; j < n; j++)
				cout << "* ";
		else
			for (int j = 0; j < n; j++)
				cout << " *";
		puts("");
	}
	return 0;
}