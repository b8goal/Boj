#include <iostream>
#include <cstring>

using namespace std;

int n,m;
int arr[500+5][500+5];
long long cache[500+5][500+5];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

long long dfs(int x, int y) {
  if(x < 1 || y < 1 || x > n || y > m) return 0;
  if(x == n && y == m) return 1;

  long long& ret = cache[x][y];
  if(ret != -1) return ret;
  ret = 0;

  for(int k=0; k<4; k++) {
    int nx = x+dx[k], ny = y+dy[k];
    if(arr[x][y] > arr[nx][ny]) {
      ret += dfs(nx,ny);
    }
  }

  return ret;
}
  
int main(void)
{
  //cin.sync_with_stdio(false);
  //cout.sync_with_stdio(false);

  //freopen("../txt/input.txt", "r", stdin);
  //freopen("../txt/output.txt","w",stdout);

  memset(cache, -1, sizeof(cache));

  cin >> n >> m;

  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      cin >> arr[i][j];
    }
  }

  cout << dfs(1,1) << '\n';

  return 0;
}