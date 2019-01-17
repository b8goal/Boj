#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <functional>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <cmath>
#include <map>
#include <stack>
#define C 10
using namespace std;

typedef long long ll;
const int INF = 100000000;
const int MOD = 1000000007;
const int MAXN = 4000;

int abs(int x) { return x > 0 ? x : -x; }
int a[1500][1500];
int main(void) {
	string s;
	int a[4] = { 0,0,0,0 };
	a[0] = 1; a[3] = 2;
	cin >> s;
	for (int i = 0; i<s.length(); i++) {
		if (s[i] == 'A')
			swap(a[0], a[1]);
		else if (s[i] == 'B')
			swap(a[0], a[2]);
		else if (s[i] == 'C')
			swap(a[0], a[3]);
		else if (s[i] == 'D')
			swap(a[1], a[2]);
		else if (s[i] == 'E')
			swap(a[1], a[3]);
		else if (s[i] == 'F')
			swap(a[2], a[3]);
	}
	for (int i = 0; i < 4; i++)
		if (a[i] == 1)
			cout << i + 1 << '\n';
	for (int i = 0; i < 4; i++)
		if (a[i] == 2)
			cout << i + 1 << '\n';

	return 0;
}