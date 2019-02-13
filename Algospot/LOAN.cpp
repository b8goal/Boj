#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <bitset>
#include <random>
#include <ctime>
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define REP(i,n) FOR(i,0,n)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
const int MOD = 1e9 + 9;
const int INF = 0x7fffffff;
const int MIN = -32768 * 101;
const int MAXN = 100000 + 1;
const long double PI = 3.141592653589793238462643383279502884197;
int p[100];
int find(int x) { return p[x] ^ x ? find(p[x]) : x; }
void merge(int x, int y) { p[find(y)] = find(x); }
int abs(int x, int y) { return x - y > 0 ? x - y : y - x; }
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int min(int x, int y) { return x > y ? y : x; }
ll max(ll x, ll y) { return x > y ? x : y; }
/*int pow(int x, int y) {
	if (y == 0) return 0;
	if (y == 1) return x;
	if (y % 2 == 0) {
		int ret = pow(x, y / 2);
		return ret = (ret * ret);
	}
	else {
		int ret = pow(x, (y - 1) / 2);
		return ret = ret * ret*x;
	}
}*/

// amount원을 연 이율 rates퍼센트로 duration월 간 한 달에 monthlyPayment로 남았을 떄 대출 잔금은?
double balance(double amount, int duration, double rates, double monthPayment) {
	double balance = amount;
	for (int i = 0; i < duration; ++i) {
		// 이자가 붙는다.
		balance *= (1.0 + (rates / 12.0) / 100.0);
		// 상환액을 잔금에서 제한다.
		balance -= monthPayment;
	}
	return balance;
}

// amount원을 연  이율 rates퍼센트로 duration월 간 갚으려면 한 달에 얼마씩 갚아야 하나?
double payment(double amount, int duration, double rates) {
	// 불변 조건
	// 1. lo원씩 갚으면 duration개월 안에 갚을 수 없다.
	// 2. hi원씩 갚으면 duration개월 안에 갚을 수 있다.
	double lo = 0, hi = amount * (1.0 + (rates / 12.0) / 100.0);
	for (int iter = 0; iter < 100; ++iter) {
		double mid = (lo + hi) / 2.0;
		if (balance(amount, duration, rates, mid) <= 0)
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

int main(void) {
	int n;
	scanf("%d", &n);
	while (n--) {
		int m;
		double n,c;
		scanf("%lf %d %lf", &n, &m, &c);
		printf("%.10lf\n", payment(n, m, c));
	}
	return 0;
}