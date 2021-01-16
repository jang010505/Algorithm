def dfs(now, prv):
    global chk
    for nxt in node[now]:
        if nxt!=prv and visit[nxt]==1:
            chk=0
        elif visit[nxt]==0:
            visit[nxt]=1
            dfs(nxt, now)
n, m=map(int, input().split())
test=1
while n!=0 or m!=0:
    node=[[] for i in range(n+1)]
    for i in range(m):
        x, y=map(int, input().split())
        node[x].append(y)
        node[y].append(x)
    answer=0
    visit=[0]*(n+1)
    for i in range(1, n+1):
        if visit[i]==0:
            visit[i]=1
            chk=1
            dfs(i, -1)
            if chk:
                answer+=1
    if answer>1:
        print("Case %d: A forest of %d trees." %(test, answer))
    elif answer:
        print("Case %d: There is one tree." %(test))
    else:
        print("Case %d: No trees." %(test))
    n, m=map(int, input().split())
    test+=1
