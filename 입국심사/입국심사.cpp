#include <iostream>
#include <limits>

using namespace std;

unsigned long long ans;
int n,m;
unsigned long long arr[100000+5];

unsigned long long func(unsigned long long x) {
  unsigned long long cnt = 0;
  for(int i=0; i<n; i++) {
    cnt += x/arr[i];
  }

  return cnt;
}

int main(void)
{
  //cin.sync_with_stdio(false);
  //cout.sync_with_stdio(false);

  //freopen("../txt/input.txt", "r", stdin);
  //freopen("../txt/output.txt","w",stdout);

  cin >> n >> m;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  } 

  unsigned long long lo,mid,hi;
  ans = hi = 1e19;
  lo = 1;
  while(lo <= hi) {
    mid = (hi-lo)/2 + lo;
    func(mid) >= m ? hi = mid-1 : lo = mid+1;
  }

  cout << lo << '\n';
  
  return 0;
}