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

//단일 변수 다항식 p의 게수가 주어질 때 미분한 결과 p의 계수를 반환한다.
vector<double> differentiate(const vector<double>& poly) {
	int n = poly.size() - 1;
	vector<double> result;
	//미분
	for (int i = 0; i < n; i++)
		result.push_back((n - i)*poly[i]);
	return result;
}
// 1차 혹은 2차 방정식을 푼다
vector<double> solveNaive(const vector<double>& poly) {
	int n = poly.size() - 1;
	vector<double> result;
	switch (n)
	{
	case 1:
		result.push_back(-poly[1] / poly[0]);
		break;
	case 2:
		double a = poly[0], b = poly[1], c = poly[2];
		//근의 공식
		result.push_back((-b + sqrt(pow(b, 2) - 4 * a*c)) / (2 * a));
		result.push_back((-b - sqrt(pow(b, 2) - 4 * a*c)) / (2 * a));
		break;
	}
	sort(result.begin(), result.end());
	return result;
}
// 다항식 f(x)의 계수 poly가 주어질 때, f(x0)를 반환한다.
double evaluate(const vector<double>&poly, double x0) {
	int n = poly.size() - 1;
	double result = 0;
	//대입
	for (int i = 0; i <= n; i++)
		result += pow(x0, n - i)*poly[i];
	return result;
}
// 방정식의 해의 절대 값은 L이하여야 한다.

const double L = 25;

vector<double> solve(const vector<double>&poly) {
	int n = poly.size() - 1;
	// 기저 사례: 2차 이하의 방정식들은 풀 수 있다.
	if (n <= 2) return solveNaive(poly);
	// 방정식을 미분해서 n-1차 방정식을 얻는다.
	vector<double> derivative = differentiate(poly);
	vector<double> sols = solve(derivative);
	// 이 극점들 사이를 하나하나 검사하며 근이 있나 확인한다.
	sols.insert(sols.begin(), -L - 1);
	sols.insert(sols.end(), L + 1);
	vector<double> ret;
	for (int i = 0; i + 1 < sols.size(); ++i) {
		double x1 = sols[i], x2 = sols[i + 1];
		double y1 = evaluate(poly, x1), y2 = evaluate(poly, x2);
		// f(x1)과 f(x2)의 부호가 같은 경우 답은 없다.
		if (y1*y2 > 0) continue;
		// 불변 조건: f(x1) <= 0 < f(x2)
		if (y1 > y2) { swap(y1, y2); swap(x1, x2); }
		// 이분법을 사용하자.
		for (int iter = 0; iter < 100; ++iter) {
			double mx = (x1 + x2) / 2;
			double my = evaluate(poly, mx);
			if (y1*my > 0) {
				y1 = my;
				x1 = mx;
			}
			else {
				y2 = my;
				x2 = mx;
			}
		}
		ret.push_back((x1 + x2) / 2);
	}
	sort(ret.begin(), ret.end());
	return ret;
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		vector<double> poly(n+1);
		REP(i, n+1) scanf("%lf", &poly[i]);
		vector<double> ret = solve(poly);
		REP(i, sz(ret)) printf("%.12lf ", ret[i]);
		puts("");
	}
	return 0;
}