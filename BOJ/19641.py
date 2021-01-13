import sys
sys.setrecursionlimit(10**6)
count=1
def dfs(now):
    global count
    answer[now].append(count)
    count+=1
    for nxt in node[now]:
        if visit[nxt]==0:
            visit[nxt]=1
            dfs(nxt)
            visit[nxt]=0
    answer[now].append(count)
    count+=1
n=int(input())
node=[[] for i in range(n+1)]
answer=[[] for i in range(n+1)]
for i in range(n):
    tmp=list(map(int, input().split()))
    for j in range(1, len(tmp)-1):
        node[tmp[0]].append(tmp[j])
    node[tmp[0]].sort()
s=int(input())
visit=[0]*(n+1)
visit[s]=1
dfs(s)
for i in range(1, n+1):
    print(i, answer[i][0], answer[i][1])
