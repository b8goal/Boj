#include <stdio.h>
#include <algorithm>
#include <cstring>
#define MAX 4000000
using namespace std;

int factorial(int k)
{
	if (k == 0) return 1;
	if (k == 1)return 1;
	return k * factorial(k - 1);
}
int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	int a, b, c;
	a = factorial(n);
	b = factorial(n - k);
	c = factorial(k);
	printf("%d\n", a / (b*c));
	return 0;
}