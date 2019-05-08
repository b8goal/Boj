#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
#include <cstdio>
using namespace std;
const int MAX_N = 100000;
int a[MAX_N + 1], ans[MAX_N + 1];
int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	int val = 0, cnt = 0;
	stack<int> s;
	queue<char> q;
	while (val < n)
	{
		val++;
		s.push(val);
		q.push('+');

		while (!s.empty() && s.top() == a[cnt])
		{
			cnt++;
			q.push('-');
			s.pop();
		}
	}
	
	if (!s.empty()) printf("NO\n");
	else while (!q.empty())
		printf("%c\n", q.front()), q.pop();
	return 0;
}