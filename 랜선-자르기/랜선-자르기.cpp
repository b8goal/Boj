#include <iostream>
#include <limits>

using namespace std;

int n,k;
int arr[1000000+5];

long long func(unsigned int mid) {
  long long cnt = 0;

  for(int i=0; i<n; i++) {
    cnt += arr[i]/mid;
  }

  return cnt;
}

int main(void)
{
  //cin.sync_with_stdio(false);
  //cout.sync_with_stdio(false);

  //freopen("../txt/input.txt", "r", stdin);
  //freopen("../txt/output.txt","w",stdout);

  cin >> k >> n;

  for(int i=0; i<k; i++) {
    cin >> arr[i];
  }

  unsigned int lo,hi,mid, ans = 0;
  lo = 1;
  hi = numeric_limits<int>::max();

  while(lo <= hi) {
    mid = (hi - lo) / 2 + lo;

    long long ret = func(mid);

    if(ret >= n) {
      lo = mid + 1;
      ans = max(ans, mid);
    } else {
      hi = mid - 1;
    }
  }

  cout << ans <<'\n';
  
  return 0;
}