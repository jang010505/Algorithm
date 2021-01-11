n=int(input())
node=[[] for i in range(n+1)]
for i in range(n-1):
    a, b=map(int, input().split())
    node[a].append(b)
    node[b].append(a)
visit=[0]*(n+1)
stack=[1]
visit[1]=1
count=0
while stack:
    now=stack.pop()
    for t in node[now]:
        if len(node[t])==1:
            visit[t]=1+visit[now]
            count+=visit[t]-1
            continue
        if visit[t]==0:
            visit[t]=1+visit[now]
            stack.append(t)
if count%2: print("Yes")
else: print("No")
