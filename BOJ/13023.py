def dfs(x, cnt):
    visit[x]=1
    if cnt==4:
        print(1)
        exit()
    for i in node[x]:
        if visit[i]==0:
            dfs(i, cnt+1)
    visit[x]=0
n, m=map(int, input().split())
node=[[] for i in range(n)]
for i in range(m):
    a, b=map(int, input().split())
    node[a].append(b)
    node[b].append(a)
for i in range(n):
    stack=[i]
    visit=[0]*(n)
    dfs(i, 0)    
print(0)
