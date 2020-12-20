n, m, v=map(int, input().split())
list_=[]
for i in range(n):
    list_.append([])
for i in range(m):
    a, b=map(int, input().split())
    list_[a-1].append(b-1)
    list_[b-1].append(a-1)
for i in range(n):
    list_[i].sort()
visit=[0]*n
dfs=[]
dfs.append(v-1)
while len(dfs)!=0:
    now=dfs.pop()
    if visit[now]==0: print(now+1, end=' ')
    visit[now]=1
    for i in reversed(list_[now]):
        if visit[i]==0:
            dfs.append(i)
print()
for i in range(n):
    visit[i]=0
bfs=[]
bfs.append(v-1)
while len(bfs)!=0:
    now=bfs.pop(0)
    if visit[now]==0: print(now+1, end=' ')
    visit[now]=1
    for i in list_[now]:
        if visit[i]==0:
            bfs.append(i)
