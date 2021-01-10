n=int(input())
list_x=[]
max_n=1
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
for i in range(n):
    list_x.append(list(map(int, input().split())))
for i in range(1, 101):
    visit=[[0]*n for j in range(n)]
    cnt=0
    for j in range(n):
        for k in range(n):
            if visit[j][k]==0 and list_x[j][k]>i:
                cnt+=1
                stack=[]
                stack.append((j, k))
                visit[j][k]=1
                while stack:
                    now_i, now_j=stack.pop()
                    for t in d:
                        I=now_i+t[0]
                        J=now_j+t[1]
                        if 0<=I<n and 0<=J<n:
                            if visit[I][J]==0 and list_x[I][J]>i:
                                stack.append((I, J))
                                visit[I][J]=1
    max_n=max(max_n, cnt)
print(max_n)
                
