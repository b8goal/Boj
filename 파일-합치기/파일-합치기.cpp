#include <iostream>
#include <cstring>

using namespace std;

int n;
int arr[500+5];
int sum[500+5];
int cache[500+5][500+5];

int func(int i, int j) {
  if(i==j) return 0;

  int& ret = cache[i][j];
  if(ret != -1) return ret;

  for(int k=i; k<=j-1; k++) {
    int temp = func(i, k) + func(k+1, j) + sum[j] - sum[i-1];
    if(ret == -1 || ret > temp) {
      ret = temp;
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



  int tc;
  cin >> tc;
  while(tc--) {
    memset(arr, 0, sizeof(arr));
    memset(sum, 0, sizeof(sum));
    memset(cache, -1, sizeof(cache));

    cin >> n;

    for(int i=1; i<=n; i++) {
      cin >> arr[i];
      sum[i] = sum[i-1] + arr[i];
    }

    cout << func(1,n) << '\n';
  }
  
  return 0;
}