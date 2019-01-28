a,b = map(str,input().split())
c = a*int(a)
if(len(a)*int(a)<int(b)):
    print(c)
else:
    for i in range(int(b)):
        print(c[i],end='')