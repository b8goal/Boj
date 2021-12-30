#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,k;
int arr[100+5][100+5];
int chk[100+5][100+5];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int dfs(int x,int y,int cnt) {
  for(int i=0; i<4; i++) {
    int nx = x+dx[i], ny = y+dy[i];
    if(nx < 0 || ny < 0 || nx > n-1 || ny > m-1) continue;
    if(chk[nx][ny] == 0 && arr[nx][ny] == 0) {
      chk[nx][ny] = 1;
      cnt = dfs(nx,ny,cnt+1);
    }
  }
  return cnt;
}

int main(void)
{
  //cin.sync_with_stdio(false);
  //cout.sync_with_stdio(false);

  //freopen("../txt/input.txt", "r", stdin);
  //freopen("../txt/output.txt","w",stdout);

  cin >> n >> m >> k;

  while(k--) {
    int sx,sy,ex,ey;
    cin >> sy >> sx >> ey >> ex;

    for(int i=sx; i<ex; i++) {
      for(int j=sy; j<ey; j++) {
        arr[i][j] = 1;
      }
    }
  }

  vector<int> ans;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(chk[i][j] == 0 && arr[i][j] == 0) {
        chk[i][j] = 1;
        int cnt = dfs(i,j,1);
        ans.push_back(cnt);
      }
    }
  }

  cout << ans.size() <<'\n';
  sort(ans.begin(), ans.end());
  for(auto iter : ans) {
    cout << iter << " ";
  }
  return 0;
}