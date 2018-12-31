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
#include <stack>
#define C 10
using namespace std;

const int INF = 1000000000;
const int MOD = 998244353;
const int MAXN = 100000;

int main(void) {
	while (1) {
		int flag = 1;
		stack<char> p;
		string s;
		getline(cin, s);
		if (s.size() == 1 && s[0] == '.') break;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '[' || s[i] == '(')
				p.push(s[i]);
			else if (s[i] == ']') {
				if (p.empty()) {
					flag = 0;
					break;
				}
				else if(p.top() == '[')
					p.pop();
				else {
					flag = 0;
					break;
				}
			}
			else if (s[i] == ')') {
				if (p.empty()) {
					flag = 0;
					break;
				}
				else if (p.top() == '(')
					p.pop();
				else {
					flag = 0;
					break;
				}
			}
		}
		if (flag && p.empty()) puts("yes");
		else puts("no");
	}
	return 0;
}