#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

bitset<33554432> b;
int n;

int main(void) {
	while (scanf("%d", &n) != EOF) {
		if (!b[n]) printf("%d ", n);
		b[n] = 1;
	}
	return 0;
}