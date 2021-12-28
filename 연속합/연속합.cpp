#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  //cin.sync_with_stdio(false);
  //cout.sync_with_stdio(false);

  //freopen("../txt/input.txt", "r", stdin);
  //freopen("../txt/output.txt","w",stdout);

  int n;
  cin >> n;

  vector<long long> arr(n+1);
  for(int i=1; i<=n; i++) {
    cin >> arr[i];
  }

  long long sum = 0, ans = -1000 * 100000;
  for(int i=1; i<=n; i++) {
    sum = max(arr[i], sum + arr[i]);
    ans = max(ans, sum);
  }

  cout << ans << '\n';
  
  return 0;
}