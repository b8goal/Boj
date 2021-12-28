#include <iostream>
#include <cstring>

using namespace std;

const int max_n = 1000 + 5;
const int max_m = 1000 + 5;

int arr[max_n][max_m];
int dp[max_n][max_m];
int n,m,ans;
int dx[3] = {1,0,1};
int dy[3] = {0,1,1};

int main(void)
{
  //cin.sync_with_stdio(false);
  //cout.sync_with_stdio(false);

  //freopen("../txt/input.txt", "r", stdin);
  //freopen("../txt/output.txt","w",stdout);

  cin >> n >> m;

  memset(arr, 0, sizeof(arr));
  memset(dp, 0, sizeof(dp));

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      cin >> arr[i][j];
    }
  }

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      dp[i][j] = max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + arr[i][j];
    }
  }

  cout << dp[n][m] << '\n';
  
  return 0;
}