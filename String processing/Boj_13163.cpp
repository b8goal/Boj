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
using namespace std;

const int INF = 987654321;
const int MOD = 998244353;
const int MAXN = 52;

int main(void) {
	int n;
	cin >> n;
	while (n--) {
		char str[105];
		bool flag = 1;
		cin >> str;
		fgets(str, 105, stdin);
		cout << "god";
		for (int i = 0; str[i]; i++) {
			if (flag) {
				if (str[i] == ' ')
					flag = 0;
			}
			if (!flag)
				if (str[i] != ' ')
					cout << str[i];
		}
	}
	return 0;
}