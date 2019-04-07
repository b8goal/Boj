#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

vector<tuple<int, int, int, string> > v;
int main(void) {
	int n, a, b, c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s >> a >> b >> c;
		v.push_back({ c,b,a,s });
	}
	sort(v.begin(), v.end());
	string ss[2];
	tie(a, b, c, ss[0]) = v[0];
	tie(a, b, c, ss[1]) = v[n - 1];
	cout << ss[1] << '\n' << ss[0] << '\n';
	return 0;
}