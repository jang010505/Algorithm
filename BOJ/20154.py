n, m=map(int, input().split())
d=[]
for i in range(31):
    d.append([])
    for j in range(31):
        d[i].append(0)
    d[0][i]=1
for i in range(1, 31):
    for j in range(i, 31):
        d[i][j]=d[i-1][j]+d[i][j-1]
res=abs(n-m)
print(d[res][res])
