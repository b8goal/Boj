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

int main(void) {
	int a, b, r, c;
	scanf("%d %d %d %d", &r, &c, &a, &b);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < a; j++) {
			for (int k = 0; k < c; k++) {
				if ((i + k) % 2 == 0)
					for (int l = 0; l < b; l++) printf("X");
				else
					for (int l = 0; l < b; l++) printf(".");
			}
			puts("");
		}
	}
	return 0;
}