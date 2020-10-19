a, b, c=map(int, input().split())
if a==b and b==c: print(2)
elif a*a==b*b+c*c or b*b==a*a+c*c or c*c==a*a+b*b: print(1)
else: print(0)
