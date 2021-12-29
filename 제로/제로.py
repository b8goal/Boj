from collections import deque
k = int(input())
a = deque()
for _ in range(k):
  b = int(input())
  if b==0:
    a.pop()
  else:
    a.append(b)
print(sum(a))