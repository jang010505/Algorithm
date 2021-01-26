import sys
sys.setrecursionlimit(10**5)
def dfs(now):
    visit[now]+=1
    for nxt in node[now]:
        if visit[nxt]==0:
            visit[nxt]=visit[now]
            parent[nxt]=now
            dfs(nxt)
n=int(input())
node=[[] for i in range(n+1)]
for i in range(n-1):
    a, b=map(int, input().split())
    node[b].append(a)
    node[a].append(b)
visit=[0]*(n+1)
parent=[0]*(n+1)
dfs(1)
for i in range(int(input())):
    fir, sec=map(int, input().split())
    if visit[fir]<visit[sec]:
        sec, fir=fir, sec
    while visit[fir]!=visit[sec]:
        fir=parent[fir]
    while fir!=sec:
        fir=parent[fir]
        sec=parent[sec]
    print(fir)
