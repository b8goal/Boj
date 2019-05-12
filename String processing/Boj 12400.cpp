#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
char a[26] = { 'y','h','e','s','o','c','v','x','d','u',
			'i','g','l','b','k','r','z','t','n','w',
			'j','p','f','m','a','q' };
int main(void) {
	int tc;
	string s;
	cin >> tc;
	getline(cin, s);
	for(int t=1;t<=tc; t++){
		getline(cin, s);
		cout << "Case #" << t << ": ";
		for (int i = 0; s[i]; i++) {
			if (s[i] >= 'a'&&s[i] <= 'z')
				cout << a[s[i]-'a'];
			else
				cout << s[i];
		}
		cout << '\n';
	}
	return 0;
}