a = [[0 for i in range(1001)] for j in range(1001)]

for i in range(1001):
    for j in range(1001):
        if i == j or j == 0:
            a[i][j]=1
        else:
            a[i][j] = a[i-1][j-1]+a[i-1][j]
n,k = map(int,input().split())
print(a[n][k]%10007)