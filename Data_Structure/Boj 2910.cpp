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
const int MAXN = 4000;

bool comp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
	if (a.second.first == b.second.first)
		return a.second.second < b.second.second;
	return a.second.first > b.second.first;
}
int main(void) {
	int n, c;
	scanf("%d %d", &n, &c);
	map<int, pair<int,int> > mp;
	for (int i = 0,x; i < n; i++) {
		scanf("%d", &x);
		auto iter = mp.find(x);
		if (iter != mp.end()) 
			mp[x] = { iter->second.first + 1,iter->second.second };
		else 
			mp[x] = { 1,i };
	}
	vector<pair<int,pair<int,int> > >v(mp.begin(), mp.end());
	sort(v.begin(), v.end(), comp);
	
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].second.first; j++) {
			printf("%d ", v[i].first);
		}
	}

	return 0;
}