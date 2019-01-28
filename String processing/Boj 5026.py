n = int(input())
while n:
    n-=1
    _ = input()
    if _ == "P=NP":
        print("skipped")
        continue
    else:
        a,b = map(int, _.split('+'))
        print(a+b)