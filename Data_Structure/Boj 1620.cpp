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
#include <math.h>
#include <map>
#include <stack>
#define C 10
using namespace std;

const int INF = 100000000;
const int MOD = 45678;
const int MAXN = 100000;

string mp2[100001];
int main(void) {
	int n, m;
	cin >> n >> m;

	map<string, int> mp1;
	for(int i=1; i<=n; i++) {
		char str[1000];
		scanf("%s", str);
		mp2[i] = str;
		mp1[str] = i;
	}
	while (m--) {
		char str[1000];
		scanf("%s", str);
		if (str[0] >= '0'&&str[0] <= '9')
			cout << mp2[stoi(str)] << '\n';
		else
			cout << mp1[str] << '\n';
	}
	return 0;
}