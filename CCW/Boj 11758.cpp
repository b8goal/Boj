#include <iostream>
#include <algorithm>
#define MAX 300
using namespace std;
int A[MAX + 1];
int dp[MAX + 1][3];
int main()
{
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	int k1, k2;
	k1 = x1*y2 + x2*y3 + x3*y1;
	k2 = y1*x2 + y2*x3 + y3*x1;

	if (k1 - k2 > 0)
		cout << "1" << '\n';
	else if (k1 - k2 == 0)
		cout << "0" << '\n';
	else cout << "-1" << '\n';
	return 0;
}