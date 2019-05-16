#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

bool cmp(const string &s1, const string &s2) {
	if (s1.size() == s2.size())
		return s1 < s2;
	else
		return s1.size() < s2.size();
}
int main(void) {
	int m, tmp, f = 0;
	cin >> m;
	vector<string> v;
	while (m--) {
		string s, num;
		cin >> s;
		queue<char> st;
		num = "";
		s += 'x';
		f = 0;
		for (int i = 0; s[i]; i++) {
			if ('0' <= s[i] && s[i] <= '9') {
				if (s[i] == '0' && f != 2) {
					f = 1;
					continue;
				}
				f = 2;
				num += s[i];
			}
			else if (f != 0) {
				if (f == 1) 
					num = "0";
				v.push_back(num);
				f = 0;
				num = "";
			}
		}
	}
	sort(v.begin(), v.end(),cmp);
	for (auto it : v)
		cout << it << '\n';
	return 0;
}