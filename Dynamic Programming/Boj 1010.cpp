#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


#define MAX 1000000001
#define MOD 1000000007

using namespace std;

int dp[31][31];

int main(void)
{
	dp[0][0] = 1;
	for (int i = 1; i <= 30; i++)
	{
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		int a, b;
		cin >> a >> b;
		if (b > a)
			swap(a, b);
		cout << dp[a][b] << '\n';
	}
	return 0;
}