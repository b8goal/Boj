import sys

for _ in range(3):
    n = int(input())
    a = [sys.stdin.readline() for i in range(n)]
    if sum(list(map(int,a))) == 0:
        print(0)
    elif sum(list(map(int,a))) > 0:
        print('+')
    else:
        print('-')