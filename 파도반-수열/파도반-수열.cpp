#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  //cin.sync_with_stdio(false);
  //cout.sync_with_stdio(false);

  //freopen("../txt/input.txt", "r", stdin);
  //freopen("../txt/output.txt","w",stdout);
  int tc;
  cin>> tc;
  vector<unsigned long long> dp(100 + 1);
  
  dp[1] = dp[2] = dp[3] = 1;
  dp[4] = dp[5] = 2;

  for(int i=6; i<=100; i++) {
    dp[i] = dp[i-1] + dp[i-5];
  }

  while(tc--) {
    int n;
    cin >> n;
    cout << dp[n] <<'\n';
  }
  
  return 0;
}