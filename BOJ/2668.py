def dfs(start, now):
    
    if visit[now]:
        if start==now:
            answer.append(start)
    else:
        visit[now]=1
        dfs(start, list_x[now])
n=int(input())
answer=[]
list_x=[0]*(n+1)
for i in range(1, n+1):
    list_x[i]=int(input())
for i in range(1, n+1):
    visit=[0]*(n+1)
    dfs(i, i)
answer.sort()
print(len(answer))
print('\n'.join(map(str, answer)))
