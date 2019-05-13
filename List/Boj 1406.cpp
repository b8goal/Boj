#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

list<char> li;
int main(void) {
	string s;
	cin >> s;
	for (int i = 0; s[i]; i++)
		li.push_back(s[i]);
	int n;
	char x, y;
	cin >> n;
	list<char>::iterator it = li.end();
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 'P') {
			cin >> y;
			li.insert(it, y);
		}
		else if (x == 'L' && it != li.begin())
			--it;
		else if (x == 'D' && it != li.end())
			++it;
		else if (x == 'B' && it != li.begin()){
			--it;
			it = li.erase(it);
		}
	}
	for (auto t : li) {
		cout << t;
	}
	return 0;
}

