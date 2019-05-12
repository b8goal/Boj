a , b = input().split()
t_a = t_b = 0
tmp = 1
for i in range(len(a)-1,-1,-1):
    if a[i] == '1' :
        t_a += tmp
    tmp *=2
tmp = 1
for i in range(len(b)-1,-1,-1):
    if b[i] == '1' :
        t_b += tmp
    tmp *=2
print(format(t_a+t_b,'b'))