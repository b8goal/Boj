#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

char str[35];
stack<int> s;
int main(void) {
	scanf("%s", &str);
	int len = strlen(str);
	int mul = 1, sum = 0;

	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(') {
			mul *= 2;
			s.push(str[i]);
			if (i + 1 < len && str[i + 1] == ')')sum += mul;
		}
		else if (str[i] == '[') {
			mul *= 3;
			s.push(str[i]);
			if (i + 1 < len && str[i + 1] == ']') sum += mul;
		}

		if (str[i] == ')') {
			if (s.empty()) {
				puts("0");
				return 0;
			}
			mul /= 2;
			if (s.top() == '(')
				s.pop();
			else if(s.top()!='('){
				cout << 0 << '\n';
				return 0;
			}
		}
		else if (str[i] == ']') {
			if (s.empty()) {
				puts("0");
				return 0;
			}
			mul /= 3;
			if (s.top() == '[')
				s.pop();
			else if (s.top() != '[') {
				cout << 0 << '\n';
				return 0;
			}
		}
	}
	if (!s.empty())
		sum = 0;
	printf("%d", sum);

	return 0;
}
