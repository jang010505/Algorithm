a=[]
a.append(1)
a.append(2)
for i in range(2, 101):
    a.append(a[i-1]+a[i-2])
n=int(input())
for i in range(n):
    x=int(input())
    res=[]
    for i in range(100, -1, -1):
        X=x
        while x>=0:
            x-=a[i]
        x+=a[i]
        if x!=X: res.append(a[i])
        if x==0: break
    sorted(res)
    for i in range(len(res)-1, -1 , -1):
        print(res[i], end=' ')
    print()
