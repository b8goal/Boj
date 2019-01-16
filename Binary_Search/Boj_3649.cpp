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

int x, n;
int binary_search(vector<int> &v, int s, int e,int num) {
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (v[mid] == num) return mid;
		else if (v[mid] < num) s = mid + 1;
		else e = mid - 1;
	}
	return -1;
}
int main(void) {
	while (scanf("%d", &x) == 1) {
		x *= 10000000;
		scanf("%d", &n);
		vector<int> v;
		for (int i = 0,k; i < n; i++) {
			scanf("%d", &k);
			v.push_back(k);
		}
		sort(v.begin(), v.end(),less<int>());
		int flag = 1;
		for (int i = 0; i < n; i++) {
			int tmp = binary_search(v, i+1,n-1,x-v[i]);
			if (tmp != -1) {
				printf("yes %d %d\n", v[i], v[tmp]);
				flag = 0;
				break;
			}
		}
		if (flag) puts("danger");
	}
	return 0;
}