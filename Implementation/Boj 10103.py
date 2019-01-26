n = int(input())
c=s=100
while n:
    n-=1
    a,b=map(int,input().split())
    if a>b:
        s-=a
    elif a<b:
        c-=b
print (c,s,sep='\n')