import sys
sys.setrecursionlimit(10**5)
def dfs(now, count):
    if visit[now]==1:
        print(-1)
        exit()
    if node[now]==0:
        print(count)
        exit()
    else:
        visit[now]=1
        dfs(node[now], count+1)
n, m, p=map(int, input().split())
node=[0]*(m+1)
for i in range(n):
    fav, hat=map(int, input().split())
    if node[hat]==0:
        node[hat]=fav
visit=[0]*(m+1)
dfs(p, 0)
