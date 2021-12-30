#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(void)
{
  //cin.sync_with_stdio(false);
  //cout.sync_with_stdio(false);

  //freopen("../txt/input.txt", "r", stdin);
  //freopen("../txt/output.txt","w",stdout);

  int n,k;
  int arr[100+5];
  int cache[10000+5];
  cin >> n >> k;
  for(int i=1; i<=n; i++) {
    cin >> arr[i];
  }

  memset(cache, 0, sizeof(cache));

  cache[0] = 1;
  for(int i=1; i<=n; i++) {
    for(int j=0; j<=k; j++) {
      if(j-arr[i] >= 0) {
        cache[j] += cache[j - arr[i]];
      }      
    }
  }
  
  cout << cache[k] <<'\n';

  return 0;
}