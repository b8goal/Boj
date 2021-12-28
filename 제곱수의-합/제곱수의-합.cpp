#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
  //cin.sync_with_stdio(false);
  //cout.sync_with_stdio(false);

  //freopen("../txt/input.txt", "r", stdin);
  //freopen("../txt/output.txt","w",stdout);

  int n;
  cin >> n;
  vector<int> dp(n+5);

  dp[1] = 1;
  
  for(int i=2; i<=n; i++) {
    dp[i] = dp[i-1] + 1;
    for(int j=1; j*j <= i; j++) {
      dp[i] = min(dp[i - j*j] + 1, dp[i]);
    }
  }

  cout << dp[n] << '\n';
  
  return 0;
}