#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  //cin.sync_with_stdio(false);
  //cout.sync_with_stdio(false);

  //freopen("../txt/input.txt", "r", stdin);
  //freopen("../txt/output.txt","w",stdout);

  int n;
  cin >> n;
  vector<int> dp(n + 1);

  dp[0] = 1;
  dp[2] = 3;
  for(int i=4; i<=n; i+=2) {
    for(int k=i-2; k>=0; k-=2) {
      if(k == i-2) {
        dp[i] = dp[k] * 3;
      } else {
        dp[i] += dp[k] * 2;
      }
    }
  }

  cout << dp[n] <<'\n';
  
  return 0;
}