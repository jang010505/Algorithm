a=[]
a.append(0)
a.append(1)
for i in range(2, 100001):
    a.append(a[i-1]+a[i-2])
n=int(input())
for i in range(n):
    x=int(input())
    if x==1: print(2)
    else: print(a.index(x))
