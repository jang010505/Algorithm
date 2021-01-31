for _ in range(int(input())):
    n, p, q=map(int, input().split())
    people=list()
    for i in range(n):
        people.append(int(input()))
    info=[[100000000]*(p+1) for i in range(p+1)]
    for i in range(p+1):
        info[i][i]=0
    for i in range(q):
        u, v, b=map(int, input().split())
        info[u][v]=min(info[u][v], b)
        info[v][u]=min(info[v][u], b)
    for k in range(1, p+1):
        for i in range(1, p+1):
            for j in range(1, p+1):
                info[i][j]=min(info[i][j], info[i][k]+info[k][j])
    answer=10e10
    index=1
    for i in range(1, p+1):
        s=0
        for j in range(n):
            s+=info[people[j]][i]**2
        if answer>s:
            index=i
            answer=s
    print(index, answer)
