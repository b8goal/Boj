#include <iostream>
#include <algorithm>

using namespace std;

const int max_r = 1000 + 5;

int arr[max_r];
int dp[max_r];

int main(void)
{
  //cin.sync_with_stdio(false);
  //cout.sync_with_stdio(false);

  //freopen("../txt/input.txt", "r", stdin);
  //freopen("../txt/output.txt","w",stdout);

  int n, mx = 0;
  cin >> n;

  for(int i=1; i<=n; i++) {
    cin >> arr[i];
    dp[i] = 0;
  }

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=i; j++) {
      if(arr[j] > arr[i] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        mx = max(mx, dp[i]);
      }
    }
  }

  cout << mx + 1 << '\n';

  return 0;
}
