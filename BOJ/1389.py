from collections import deque
n, m=map(int, input().split())
d=[]
for i in range(n):
    d.append([101]*n)
    d[i][i]=0
for i in range(m):
    a, b=map(int, input().split())
    d[a-1][b-1]=1
    d[b-1][a-1]=1
for k in range(n):
    for i in range(n):
        for j in range(n):
            if d[i][k]+d[k][j]<d[i][j]:
                d[i][j]=d[i][k]+d[k][j]
ans=100000000000
for i in range(n):
    if ans>sum(d[i]):
        ans=sum(d[i])
        index=i
print(index+1)
