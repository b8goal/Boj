#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <tuple>
using namespace std;

pair<int,int> chk[100001];
int n, k;
queue<pair<int,int> > q;
int main(void) {
	scanf("%d %d", &n, &k);
	
	q.push({ n,0 });
	chk[n].first++;
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		if (chk[k].first)
			break;
		for (int i = 0; i < 3; i++) {
			if (i == 0 && cur.first - 1 >= 0 && (!chk[cur.first - 1].first || chk[cur.first-1].second >= chk[cur.first].second+1)) {
				chk[cur.first - 1].first++;
				chk[cur.first - 1].second = chk[cur.first].second + 1;
				q.push({ cur.first - 1,cur.second + 1 });
			}
			if (i == 1 && cur.first + 1 <= 100000 && (!chk[cur.first + 1].first || chk[cur.first + 1].second >= chk[cur.first].second + 1)) {
				chk[cur.first + 1].first++;
				chk[cur.first + 1].second = chk[cur.first].second + 1;
				q.push({ cur.first + 1,cur.second + 1 });
			}
			if (i == 2 && cur.first * 2 <= 100000 && (!chk[cur.first * 2].first || chk[cur.first *2].second >= chk[cur.first].second +1 )) {
				chk[cur.first * 2].first++;
				chk[cur.first * 2].second = chk[cur.first].second;
				q.push({ cur.first * 2,cur.second + 1 });
			}
		}
	}
	printf("%d\n", chk[k].second);
	return 0;
}
