cache = [0 for _ in range(1001)]
Mod = 10007
tc = int(input())
while tc:
    tc-=1
    n = int(input())
    cache[0] = 1; cache[1] = 2; cache[2] = 4;
    for i in range(3,n+1):
        cache[i]=cache[i-1]+cache[i-2]+cache[i-3]
    print(cache[n-1])
