import sys
sys.setrecursionlimit(10**5)
def dfs(now):
    cost=0
    for nxt in node[now]:
        if visit[nxt]==0:
            visit[nxt]=1
            cost=dfs(nxt)
            node_cnt[now]=max(node_cnt[now], cost)
    return max(node_cnt[now], cost)+1
def go(now):
    global d, answer
    for nxt in node[now]:
        if node_cnt[nxt]>=d and visit[nxt]==0:
            visit[nxt]=1
            answer+=1
            go(nxt)
n, s, d=map(int, input().split())
node=[[] for i in range(n+1)]
for i in range(n-1):
    x, y=map(int, input().split())
    node[x].append(y)
    node[y].append(x)
node_cnt=[0]*(n+1)
visit=[0]*(n+1)
visit[s]=1
dfs(s)
visit=[0]*(n+1)
answer=0
visit[s]=1
go(s)
print(answer*2)
