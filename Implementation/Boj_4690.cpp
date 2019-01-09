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
#include <tuple>
#define C 10
using namespace std;

typedef long long ll;
const int INF = 0x7fffffff;
const int MOD = 45678;
const int MAXN = 4000;

int main(void) {
	for (int i = 2; i <= 100; i++) {
		for (int j = 2; j < i; j++) {
			for (int k = j+1; k < i; k++) {
				for (int l = k+1; l < i; l++) {
					if (i*i*i == j * j*j + k * k*k + l * l*l) {
						printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, k, l);
					}
				}
			}
		}
	}
}