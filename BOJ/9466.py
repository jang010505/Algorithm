import sys
sys.setrecursionlimit(10**5)
def dfs(now):
    global count
    dfs_visit[now]=1
    if dfs_visit[list_x[now]]==0:
        dfs(list_x[now])
    elif visit[list_x[now]]==0:
        i=list_x[now]
        while i!=now:
            count+=1
            i=list_x[i]
        count+=1
    visit[now]=1
t=int(input())
for _ in range(t):
    n=int(input())
    answer=set()
    list_x=list(map(int, input().split()))
    list_x.insert(0, 0)
    count=0
    visit=[0]*(n+1)
    dfs_visit=[0]*(n+1)
    for i in range(1, n+1):
        if visit[i]==0:
            dfs(i)
    print(n-count)
