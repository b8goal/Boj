#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 1000000

int a[10001];
int dp[2][10001];
int Max(int x, int y) { return x = x > y ? x : y; }
int Min(int x, int y) { return x = x < y ? x : y; }

int main(void)
{
	int N, max = 1;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &a[i]), dp[0][i] = 1, dp[1][i] = 1;
	

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (a[i] > a[j] && dp[0][j] + 1 > dp[0][i])
				dp[0][i] = dp[0][j] + 1;
		}
	}
	for (int i = N; i >= 1; i--)
	{
		for (int j = N; j >= i; j--)
		{
			if (a[i] > a[j] && dp[1][j] + 1 > dp[1][i])
				dp[1][i] = dp[1][j] + 1;
		}
		max = Max(max, dp[0][i] + dp[1][i]);
	}
	
	printf("%d", max-1);

	return 0;
}