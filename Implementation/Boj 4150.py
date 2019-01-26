dp = [0 for i in range(10000)]
dp[0]=dp[1] =1
for i in range(2,10000):
    dp[i]=dp[i-2]+dp[i-1]
print(dp[int(input())-1])