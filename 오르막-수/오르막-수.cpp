#include <iostream>
#include <cstring>

using namespace std;

const int max_r = 1000 + 5;
const int max_c = 10 + 5;
const int mod = 10007;
int main(void)
{
  //cin.sync_with_stdio(false);
  //cout.sync_with_stdio(false);

  //freopen("../txt/input.txt", "r", stdin);
  //freopen("../txt/output.txt","w",stdout);

  int n;
  int dp[max_r][max_c];
  memset(dp, 0, sizeof(dp));
  
  cin >> n;

  for(int i=0; i<10; i++) {
    dp[1][i] = 1;
  }

  for(int i=2; i<=1000; i++) {
    for(int j=0; j<=9; j++) {
      for(int k=0; k<=j; k++) {
        dp[i][j] += dp[i-1][k];
        dp[i][j] %= mod;
      }
    }
  }

  int ans = 0;
  
  for(int i=0; i<10; i++) {
    ans = (ans + dp[n][i]) % mod;
  }

  cout << ans <<'\n';
  
  return 0;
}