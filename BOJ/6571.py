a=[]
a.append(1)
a.append(2)
for i in range(2, 1001):
    a.append(a[i-1]+a[i-2])
while 1:
    x, y=map(int, input().split())
    if x==0==y: break
    res=1
    for j in range(1001):
        if x<=a[j]:
            res-=j
            break
    for j in range(1000, -1, -1):
        if y>=a[j]:
            res+=j
            break
    if res<0: print(0)
    print(res)
