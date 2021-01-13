import sys
sys.setrecursionlimit(10**4)
def dfs(now, taget, l):
    global chk, n
    if chk==0:
        return
    if now==taget:
        print(l)
        chk=0
        return
    for i in range(1, n+1):
        if node[now][i]!=-1 and visit[i]==0:
            visit[i]=1
            dfs(i, taget, l+node[now][i])
            if chk==0:
                return
            visit[i]=0
n, m=map(int, input().split())
node=[[-1]*(n+1) for i in range(n+1)]
for i in range(n-1):
    a, b, c=map(int, input().split())
    node[a][b]=c
    node[b][a]=c
for i in range(m):
    start, end=map(int, input().split())
    visit=[0]*(n+1)
    chk=1
    visit[start]=1
    dfs(start, end, 0)
