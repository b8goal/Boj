#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
using namespace std;


int main(void) {
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++) {
		string s;
		getline(cin, s);
		cout << i << '.' << " " << s << '\n';
	}
	return 0;
}