def dfs(now):
    for nxt, cost in node[now]:
        if visit[nxt]==0:
            visit[nxt]=visit[now]+cost
            dfs(nxt)
node=[[] for i in range(100001)]
while True:
    try:
        s, e, v=map(int, input().split())
        node[s].append((e, v))
        node[e].append((s, v))
    except:
        break
visit=[0]*(10001)
dfs(1)
visit[1]=0
max_len=0
index=1
for i in range(1, 10001):
    if visit[i]>max_len:
        max_len=visit[i]
        index=i
visit=[0]*(10001)
dfs(index)
visit[index]=0
answer=0
for i in range(1, 10001):
    answer=max(answer, visit[i])
print(answer)
