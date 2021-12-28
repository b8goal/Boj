#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int max_r = 20 + 5;
const int max_c = 20 + 5;

int r,c,ans;
char arr[max_r][max_c];
int chk[26+5];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

struct pos {
  int x,y,cnt;

  pos(int _x, int _y, int _cnt) {
    x=_x, y=_y, cnt=_cnt;
  }
};

int is_range(int max_x, int max_y, int x,int y) {
  if(x < 0 || y < 0 || x >= max_x || y >= max_y) {
    return 0;
  }
  return 1;
}

void dfs(pos cur) {
  if(is_range(r, c, cur.x, cur.y) == 0) {
    return;
  }

  ans = max(ans, cur.cnt);

  for(int i=0; i<4; i++){
    pos next(0,0,0);
    next.x = cur.x + dx[i];
    next.y = cur.y + dy[i];
    next.cnt = cur.cnt + 1;
    if (chk[arr[next.x][next.y] - 'A'] == 0) {
      chk[arr[next.x][next.y] - 'A'] = 1;
      dfs(next);
      chk[arr[next.x][next.y] - 'A'] = 0;
    }
  }
}

int main(void) {

  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);

  //freopen("input.txt", "r", stdin);
  //freopen("output.txt","w",stdout);

  cin >> r >> c;
  for(int i=0; i<r; i++) {
    cin >> arr[i];
  }

  chk[arr[0][0] - 'A'] = 1;
  dfs(pos(0,0,1));

  cout << ans <<'\n';

  return 0;
}