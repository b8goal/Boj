tc = int(input())
while tc:
    tc-=1
    flag=1
    _= input()
    a = str(int(_[::-1]) + int(_))
    for i in range(0,len(a)//2):
        if a[i] != a[len(a)-1-i]:
            print("NO")
            flag=0
            break;
    if flag:
        print("YES")

'''
for i in range(int(input())):
    _= input()
    a = str(int(_[::-1]) + int(_))
    if a == a[::-1]:
        print("YES")
    else:
        print("NO")
'''