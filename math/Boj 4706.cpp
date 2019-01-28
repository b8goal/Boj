import math
while 1:
    a, b = map(float, input().split())
    if a==0 and b==0: break
    print("%0.3f" %math.sqrt((1-(b/a)**2)))