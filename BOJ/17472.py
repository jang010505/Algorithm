from collections import deque
def find(num):
    if parent[num]==num:
        return num
    parent[num]=find(parent[num])
    return parent[num]
def union(num1, num2):
    num1=find(num1)
    num2=find(num2)
    if num1==num2:
        return 0
    else:
        parent[num1]=num2
        return 1
n, m=map(int, input().split())
x_list=list()
parent=[i for i in range(11)]
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
for i in range(n):
    x_list.append(list(map(int, input().split())))
is_count=0
island=[[] for i in range(7)]
q=deque()
for i in range(n):
    for j in range(m):
        if x_list[i][j]==1:
            is_count+=1
            island[is_count].append((i, j))
            q.append((i, j))
            x_list[i][j]=is_count*-1
            while q:
                now_i, now_j=q.popleft()
                for di, dj in d:
                    nxt_i=di+now_i
                    nxt_j=dj+now_j
                    if 0<=nxt_i<n and 0<=nxt_j<m:
                        if x_list[nxt_i][nxt_j]==1:
                            x_list[nxt_i][nxt_j]=is_count*-1
                            q.append((nxt_i, nxt_j))
                            island[is_count].append((nxt_i, nxt_j))
node_info=[[11]*7 for i in range(7)]
node=list()
for i in range(1, is_count+1):
    for now_i, now_j in island[i]:
        for di, dj in d:
            nxt_i=now_i+di
            nxt_j=now_j+dj
            if 0>nxt_i or nxt_i>=n or 0>nxt_j or nxt_j>=m:
                continue
            now_island=x_list[now_i][now_j]*-1
            nxt_island=x_list[nxt_i][nxt_j]*-1
            while 0<=nxt_i<n and 0<=nxt_j<m and nxt_island!=now_island:
                if nxt_island!=0 and now_island!=nxt_island:
                    count=abs(now_i-nxt_i+now_j-nxt_j)-1
                    if count>1:
                        node_info[nxt_island][now_island]=min(node_info[nxt_island][now_island], count)
                        node_info[now_island][nxt_island]=node_info[nxt_island][now_island]
                    break
                nxt_i+=di
                nxt_j+=dj
                if 0>nxt_i or nxt_i>=n or 0>nxt_j or nxt_j>=m:
                    break
                now_island=x_list[now_i][now_j]*-1
                nxt_island=x_list[nxt_i][nxt_j]*-1
for i in range(1, is_count):
    for j in range(i+1, is_count+1):
        if node_info[i][j]!=11:
            node.append((i, j, node_info[i][j]))
node.sort(key=lambda x : x[-1])
answer=0
for go, to, cost in node:
    if union(go, to):
        answer+=cost
for i in range(1, is_count):
    if union(i, i+1):
        answer=-1
        break
print(answer)
