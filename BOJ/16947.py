import sys
sys.setrecursionlimit(10**4)
def dfs(start, now, prv):
    global chk
    for nxt in node[now]:
        if start==nxt and nxt!=prv:
            chk=1
            return
        elif visit[nxt]:
            visit[nxt]=0
            dfs(start, nxt, now)
            if chk:
                answer[nxt]=0
                return
def dfs_cnt(now):
    global count
    for nxt in node[now]:
        if answer[nxt]==0:
            count=1
            return
        elif visit[nxt]:
            visit[nxt]=0
            dfs_cnt(nxt)
            if count:
                answer[nxt]=count
                count+=1
                return
n=int(input())
node=[[] for i in range(n+1)]
answer=[-1]*(n+1)
for i in range(n):
    x, y=map(int, input().split())
    node[x].append(y)
    node[y].append(x)
chk=0
leaf_node=list()
for i in range(1, n+1):
    if len(node[i])==1:
        leaf_node.append(i)
for i in range(1, n+1):
    if chk==0:
        visit=[1]*(n+1)
        visit[i]=0
        dfs(i, i, -1)
        if chk:
            answer[i]=0
            break
for tmp in leaf_node:
    visit=[1]*(n+1)
    visit[tmp]=0
    count=0
    dfs_cnt(tmp)
    if count:
        answer[tmp]=count
answer.pop(0)
print(' '.join(map(str, answer)))
