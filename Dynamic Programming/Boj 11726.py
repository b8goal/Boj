cache = [0 for _ in range(1001)]
Mod = 10007
n = int(input())
cache[0]=1
for i in range(1,n+1):
    cache[i]=(cache[i-1%Mod]+cache[i-2]%Mod)%Mod
print(cache[n])
