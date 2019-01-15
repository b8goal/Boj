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
#define C 10
using namespace std;

typedef long long ll;
const int INF = 100000000;
const int MOD = 1000000007;
const int MAXN = 4000;

int cnt = 1;

typedef struct olyp {
	int gold, silver, bronz, number, score;

	bool operator<(const olyp &x) const{
		if (gold == x.gold) {
			if (silver == x.silver) {
					return bronz > x.bronz;
			}
				return silver > x.silver;
		}
			return gold > x.gold;
	}
};

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<olyp> v(n);
	for (int i = 0; i < n; i++){
		scanf("%d %d %d %d", &v[i].number, &v[i].gold, &v[i].silver, &v[i].bronz);
	}
	sort(v.begin(), v.end());
	v[0].score = 1;
	cnt = 1;
	for (int i = 1; i < n; i++) {
		if (v[i - 1].gold == v[i].gold && v[i - 1].silver == v[i].silver && v[i].bronz == v[i - 1].bronz) {
			++cnt;
			v[i].score = v[i - 1].score;
		}
		else{
			v[i].score = v[i - 1].score + cnt;
			cnt = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		//printf("%d %d %d %d %d\n", v[i].number, v[i].gold, v[i].silver, v[i].bronz, v[i].score);
		if (v[i].number == m) {
			printf("%d\n", v[i].score);
			return 0;
		}
	}
	return 0;
}