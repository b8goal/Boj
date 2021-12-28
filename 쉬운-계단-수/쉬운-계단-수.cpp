#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
  //cin.sync_with_stdio(false);
  //cout.sync_with_stdio(false);

  //freopen("input.txt", "r", stdin);
  //freopen("output.txt","w",stdout);

  int n;
  int dp[100+5][10];
  memset(dp, 0, sizeof(dp));
  
  cin >> n;

  for(int i=1; i<10; i++) {
    dp[1][i] = 1;
  }

  for(int i=2; i<=100; i++) {
    for(int j=0; j<=9; j++) {
      if (j == 0) {
        dp[i][j] = dp[i-1][1] % 1000000000;
      } else if (j == 9) {
        dp[i][j] = dp[i-1][8] % 1000000000;
      } else {
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
      }
    }
  }

  int ans = 0;
  for(int i=0; i<10; i++) {
    ans = (ans + dp[n][i]) % 1000000000;
  }

  cout << ans <<'\n';
  
  return 0;
}