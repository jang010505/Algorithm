from collections import deque
n, m=map(int, input().split())
visit=[0]*n
d=[]
for i in range(n):
    d.append([])
for i in range(m):
    x, y=map(int, input().split())
    d[y-1].append(x-1)
res=0
z=[]
for i in range(n):
    q=deque()
    cost=1
    q.append(i)
    visit=[0]*n
    visit[i]=1
    while q:
        now=q.popleft()
        if cost>m:
            break
        for j in d[now]:
            if visit[j]==0:
                q.append(j)
                visit[j]=1
                cost+=1
    if res<cost:
        res=cost
        z.clear()
        z.append(i+1)
    elif res==cost:
        z.append(i+1)
for i in z:
    print(i, end=' ')
