import sys
sys.setrecursionlimit(10**5)
def dfs(now, prv):
    visit[now]=1
    for i in node[now]:
        if i!=prv:
            visit[now]+=dfs(i, now)
    return visit[now]
n, r, q=map(int, input().split())
node=[[] for i in range(n+1)]
visit=[0]*(n+1)
for i in range(n-1):
    a, b=map(int, sys.stdin.readline().split())
    node[a].append(b)
    node[b].append(a)
dfs(r, 0)
for i in range(q):
    print(visit[int(sys.stdin.readline())])
