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

const int INF = 0x7fffffff;

int main(void) {
	string s;
	cin >> s;
	for (int i = 1; i <= s.size(); i++) {
		if (i % 3 == 0) {
			printf("..*.");
		}
		else
			printf("..#.");
	}puts(".");
	for (int i = 1; i <= s.size(); i++) {
		if (i % 3 == 0) {
			printf(".*.*");
		}
		else
			printf(".#.#");
	}puts(".");

	for (int i = 1; i <= s.size(); i++) {
		if (i % 3 == 0 || (i>=4 && i%3==1)) {
			printf("*.%c.",s[i-1]);
		}
		else
			printf("#.%c.",s[i-1]);		
	}if (s.size() % 3 == 0)puts("*");
	else puts("#");

	for (int i = 1; i <= s.size(); i++) {
		if (i % 3 == 0) {
			printf(".*.*");
		}
		else
			printf(".#.#");
	}puts(".");

	for (int i = 1; i <= s.size(); i++) {
		if (i % 3 == 0) {
			printf("..*.");
		}
		else
			printf("..#.");
	}puts(".");
	return 0;
}