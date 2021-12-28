#include <iostream>

using namespace std;

const int max_r = 2;
const int max_c = 100000 + 5;

int arr[max_r][max_c];
int dp[max_r][max_c];

int main(void)
{
  //cin.sync_with_stdio(false);
  //cout.sync_with_stdio(false);

  //freopen("../txt/input.txt", "r", stdin);
  //freopen("../txt/output.txt","w",stdout);

  int tc;
  cin >> tc;

  while(tc--) {
    int n;
    cin >> n;

    for(int i=0; i<2; i++) {
      for(int j=1; j<=n; j++) {
        cin >> arr[i][j];
      }
    }

    for(int j=1; j<=n; j++) {
      dp[0][j] = max(dp[0][j-1], dp[1][j-1] + arr[0][j]);
      dp[1][j] = max(dp[1][j-1], dp[0][j-1] + arr[1][j]);
    }

    cout << max(dp[0][n], dp[1][n]) << '\n';

  }
  
  return 0;
}
