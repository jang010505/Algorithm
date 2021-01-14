import sys
sys.setrecursionlimit(10**5)
def dfs(now):
    if now in dict_x:
        answer[now]+=dict_x[now]
    for nxt in node[now]:
        answer[nxt]+=answer[now]
        dfs(nxt)
n, m=map(int, input().split())
list_x=list(map(int, input().split()))
node=[[] for i in range(n+1)]
for i in range(1, n):
    node[list_x[i]].append(i+1)
answer=[0]*(n+1)
dict_x=dict()
for i in range(m):
    a, b=map(int, input().split())
    if a in dict_x:
        dict_x.update({a:b+dict_x[a]})
    else:
        dict_x.update({a:b})
dfs(1)
answer.pop(0)
print(" ".join(map(str, answer)))
