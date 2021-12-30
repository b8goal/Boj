#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
  //cin.sync_with_stdio(false);
  //cout.sync_with_stdio(false);

  //freopen("../txt/input.txt", "r", stdin);
  //freopen("../txt/output.txt","w",stdout);

  int cache[20+5];

  memset(cache, 0, sizeof(cache));

  int n;
  cin>>n;
  cache[0] = 0;
  cache[1] = 1;
  for(int i=2; i<=20; i++) {
    cache[i] = cache[i-1] + cache[i-2];
  }

  cout << cache[n] <<'\n';
  
  return 0;
}