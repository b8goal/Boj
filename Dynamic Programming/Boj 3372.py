n = int(input())

a = [list(map(int,input().split())) for _ in range(n)]
dp = [[-1]*n for i in range(n)]

def f(x, y):
    if x>n-1 or y>n-1:
        return 0
    if dp[x][y] != -1:
        return dp[x][y]
    if a[x][y] is 0:
        if x == n-1 and y == n-1:
            return 1
        else:
            return 0

    dp[x][y]=0
    dp[x][y]+=f(x+a[x][y],y)
    dp[x][y]+=f(x,y+a[x][y])
    return dp[x][y]

f(0,0)
print(dp[0][0])
