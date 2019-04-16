#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, cnt;
	cin >> n;
	cnt = n;
	for (int i = 0; i < n; i++) {
		for (int j = cnt - 1; j > 0; j--)
			cout << ' ';
		cout << '*';
		if (i){
			for (int j = 0; j < i * 2 - 1; j++)
				cout << ' ';
			cout << '*';
		}
		cout << '\n';
		cnt--;
	}
	return 0;
}