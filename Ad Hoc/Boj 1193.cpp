#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;

int dp[5001], a = 0;
int main(void)
{
	int x, i, pos = 0, cnt = 1, gap = 0;
	cin >> x;

	dp[1] = 1;
	for (int i = 1; i <= 5001; i++)
		dp[i+1] = dp[i] +i;

	while (x - dp[cnt] >= 0) cnt++;

	if (x == dp[cnt])
		gap = 0;
	gap = x - dp[cnt-1];

	cnt--;
	if (cnt % 2 == 0)
	{
		cout << 1 + gap << "/" << cnt - gap << endl;
	}
	else
		cout << cnt - gap << "/" << 1 + gap << endl;
	
	return 0;
}