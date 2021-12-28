#include <iostream>
#include <vector>

using namespace std;

unsigned long long dp[1000][1000];

int main(void)
{
  //cin.sync_with_stdio(false);
  //cout.sync_with_stdio(false);

  //freopen("../txt/input.txt", "r", stdin);
  //freopen("../txt/output.txt","w",stdout);
  
  int n,k;
  cin >> n >> k;
  int mod = 1000000000;
  dp[0][0] = 1ULL;  

  for(int i=1; i<=k; i++) {
    for(int j=0; j<=n; j++) {
      for(int l=0; l<=j; l++) {
        dp[i][j] += dp[i-1][j-l];
        dp[i][j] %= mod;
      }
    }
  }

  cout << dp[k][n] <<'\n';

  return 0;
}