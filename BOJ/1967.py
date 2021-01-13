import sys
sys.setrecursionlimit(10**4)
def dfs(now, l):
    global answer, n
    for i, cost in node[now]:
        if visit[i]==0:
            visit[i]=1
            if node_cnt[i]==1:
                answer=max(answer, l+cost)
            else:
                dfs(i, l+cost)
            visit[i]=0
answer=0
n=int(input())
node=[[] for i in range(n+1)]
node_cnt=[0]*(n+1)
for i in range(n-1):
    a, b, c=map(int, input().split())
    node[a].append((b, c))
    node[b].append((a, c))
for i in range(1, n+1):
    node_cnt[i]=len(node[i])
for i in range(1, n+1):
    if node_cnt[i]==1:
        visit=[0]*(n+1)
        visit[i]=1
        dfs(i, 0)
print(answer)
