#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main(void)
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++)
	{
		int l, n, k, mn = 0, mx = 0;
		cin >> l >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> k;
			mn = max(mn, max(l - k, k));
			mx = max(mx, min(l - k, k));
		} 
		cout << mx << " " << mn << '\n';
	}
	return 0;
}