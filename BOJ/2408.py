def f(n, m):
    if m==0 or m==n: return 1
    if d[n][m]!=0: return d[n][m]
    d[n][m]=f(n-1, m-1)+f(n-1, m)
    return d[n][m]
n, m=map(int, input().split())
d=[]
for i in range(101):
    d.append([])
    for j in range(101):
        d[i].append(0)
d[1][0], d[1][1]=1, 1
print(f(n, m))
