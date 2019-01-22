cache = [0 for _ in range(1001)]
Mod = 10007
n = int(input())
cache[0]=1; cache[1]=3
for i in range(2,n+1):
    cache[i]=(((cache[i-1])%Mod)+(2*cache[i-2])%Mod)%Mod
print(cache[n-1])
