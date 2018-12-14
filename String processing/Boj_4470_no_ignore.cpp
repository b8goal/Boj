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
	for (int i = 0; i < n + 1; i++) {
		string s;
		getline(cin, s);
		if (!i) continue;
		cout << i << '.' << " " << s << '\n';
	}
	return 0;
}