import sys
sys.setrecursionlimit(10**5)
def dfs(now):
    for nxt, cost in node[now]:
        if visit[nxt]==0:
            visit[nxt]=visit[now]+cost
            dfs(nxt)
n=int(sys.stdin.readline())
node=[[] for i in range(n+1)]
for i in range(n):
    list_x=list(map(int, sys.stdin.readline().split()))
    for j in range(1, len(list_x)-1, 2):
        node[list_x[0]].append([list_x[j], list_x[j+1]])
visit=[0]*(n+1)
dfs(1)
visit[1]=0
tmp=0
index=1
for i in range(1, n+1):
    if tmp<visit[i]:
        tmp=visit[i]
        index=i
visit=[0]*(n+1)
dfs(index)
visit[index]=0
print(max(visit))
