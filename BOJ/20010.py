def find(num):
    if parent[num]==num:
        return num
    parent[num]=find(parent[num])
    return parent[num]
def union(num1, num2):
    a=find(num1)
    b=find(num2)
    if a!=b:
        parent[b]=a
def parentFind(num1, num2):
    a=find(num1)
    b=find(num2)
    if a!=b:
        return 0
    else:
        return 1
def dfs(now):
    for nxt, cost in answer_node[now]:
        if visit[nxt]==0:
            visit[nxt]=visit[now]+cost
            dfs(nxt)
n, m=map(int, input().split())
node=list()
answer_sum=0
answer_node=[[] for i in range(n)]
for i in range(m):
    a, b, c=map(int, input().split())
    node.append((a, b, c))
parent=[i for i in range(n)]
node.sort(key = lambda x : x[-1])
for go, to, cost in node:
    if parentFind(go, to)==0:
        union(go, to)
        answer_node[go].append((to, cost))
        answer_node[to].append((go, cost))
        answer_sum+=cost
visit=[0]*n
dfs(0)
max_n=visit[0]
index=0
visit[0]=0
for i in range(n):
    if max_n<visit[i]:
        max_n=visit[i]
        index=i
visit=[0]*n
dfs(index)
visit[index]=0
print(answer_sum)
print(max(visit))
