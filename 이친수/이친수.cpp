#include <iostream>
#include <cstring>

using namespace std;

int main(void) {

  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);

  //freopen("input.txt", "r", stdin);
  //freopen("output.txt","w",stdout);

  int n, x;
  unsigned long long dp[91];
  memset(dp, 0, sizeof dp);

  dp[0] = dp[1] = dp[2] = 1;
  for (int i = 3; i <= 90; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  cin >> x;
  cout << dp[x] << '\n';

  return 0;
}