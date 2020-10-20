from math import gcd
a, b=map(int, input().split())
x=gcd(a, b)
for i in range(x):
    print('1', end='')
