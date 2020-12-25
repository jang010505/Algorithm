from collections import deque
r, c=map(int, input().split())
d=[]
x=[[0, 1], [0, -1], [1, 0], [-1, 0]]
v_res=0
o_res=0
for i in range(r):
    d.append(list(input()))
for i in range(r):
    for j in range(c):
        if d[i][j]=='v' or d[i][j]=='o':
            q=deque()
            q.append([i, j])
            o_cnt=0
            v_cnt=0
            if d[i][j]=='v': v_cnt+=1
            if d[i][j]=='o': o_cnt+=1
            d[i][j]='#'
            while q:
                q_pop=q.popleft()
                I=q_pop[0]
                J=q_pop[1]
                for k in x:
                    if 0<=I+k[0]<r and 0<=J+k[1]<c and d[I+k[0]][J+k[1]]!='#':
                        q.append([I+k[0], J+k[1]])
                        if d[I+k[0]][J+k[1]]=='v': v_cnt+=1
                        if d[I+k[0]][J+k[1]]=='o': o_cnt+=1
                        d[I+k[0]][J+k[1]]='#'
            if o_cnt>v_cnt: o_res+=o_cnt
            else: v_res+=v_cnt
print(o_res, v_res)
