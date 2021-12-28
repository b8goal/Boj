#include <iostream>
#include <string>

using namespace std;

const int mod = 1000000;
int dp[5000+5];

int main(void)
{
  //cin.sync_with_stdio(false);
  //cout.sync_with_stdio(false);

  //freopen("../txt/input.txt", "r", stdin);
  //freopen("../txt/output.txt","w",stdout);
  
  string s;
  cin >> s;
  s = '0' + s;
  dp[0] = 1;
  for(int i=1; i<s.length(); i++) {
    int num = s[i] - '0';
    if(1 <= num && num <= 9) {
      dp[i] = (dp[i] + dp[i-1]) % mod;
    }
    if(i==1) continue;
    if(s[i-1] == '0') continue;
    num = (s[i-1] - '0')*10 + (s[i] - '0');
    if(10 <= num && num <= 26) {
      dp[i] = (dp[i] + dp[i-2]) % mod;
    }
  }

  cout << dp[s.length() - 1] << '\n';

  return 0;
}