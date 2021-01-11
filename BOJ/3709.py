T=int(input())
for _ in range(T):
    n, r=map(int, input().split())
    list_x=[[0]*(n+2) for i in range(n+2)]
    for i in range(r):
        a, b=map(int, input().split())
        list_x[a][b]=1
    start_i, start_j=map(int, input().split())
    stack=[]
    if start_i==0:
        di, dj=1, 0
    elif start_i==n+1:
        di, dj=-1, 0
    elif start_j==0:
        di, dj=0, 1
    elif start_j==n+1:
        di, dj=0, -1
    stack.append((start_i, start_j, di, dj))
    while stack:
        now_i, now_j, di, dj=stack.pop()
        i, j=now_i+di, now_j+dj
        if i==0 or i==n+1 or j==0 or j==n+1:
            print(i, j)
            break
        if list_x[i][j]==1:
            if di==0 and dj==1:
                di, dj=1, 0
            elif di==0 and dj==-1:
                di, dj=-1, 0
            elif di==1 and dj==0:
                di, dj=0, -1
            elif di==-1 and dj==0:
                di, dj=0, 1
        stack.append((i, j, di, dj))
