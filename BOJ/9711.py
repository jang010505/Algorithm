n=int(input())
a=[]
a.append(1)
a.append(1)
for i in range(2, 10000):
    a.append(a[i-2]+a[i-1])
for i in range(n):
    p, q=map(int, input().split())
    print("Case #%d: %d"%(i+1, a[p-1]%q))
