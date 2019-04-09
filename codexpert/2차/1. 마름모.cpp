#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <functional>
#include <set>
#define INF 987654321
using namespace std;


int cal(char x) {
	if ('0' <= x && x <= '9')
		return x - '0';
	if ('A' <= x && x <= 'F')
		return x-'A'+10;
}

set<long long> se;
int main(void) {
	int n, k;
	char c[30];
	vector<char> v;
	vector<long long> s;
	scanf("%d %d", &n, &k);
	scanf("%s", c);
	for (int i = 0; i < n; i++)
		v.push_back(c[i]);
	
	for (int i = 0; i < n; i++) {
		long long temp = 0;
		for (int j = 0; j < n / 4; j++) {
			temp = temp * 16 + cal(v[(i + j)%n]);
		}
		se.insert(temp);
	}
	set<long long>::iterator iter;
	int cnt = 0;
	for (iter = se.begin(); iter != se.end(); iter++) {
		if (cnt == se.size()-k) {
			cout << *iter << '\n';
			return 0;
		}
		cnt++;
	}
	return 0;
}