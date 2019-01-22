n = int(input())
cache = [0 for _ in range(1000001)]
for i in range(2,1000001):
    ret = cache[i-1]
    if i%2 ==0:
        ret = min(ret,cache[int(i/2)])
    if i%3 ==0:
        ret = min(ret,cache[int(i/3)])
    cache[i]=ret+1
print(cache[n])