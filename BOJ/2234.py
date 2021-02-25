import sys
from collections import deque 

input = sys.stdin.readline

M, N = map(int, input().split())

value_lst = list()
for i in range (N) :
    v = list(map(int, input().split()))
    value_lst.append(v)

## 이동
move_x_lst = [-1,0,1,0]
move_y_lst = [0,-1,0,1]
used = [[0] *M for i in range (N)]
##
def BFS() :
    ## 풀이에 사용할 lst
    lst = deque()
    cnt = 1
    size=list()
    for i in range (N) :
        for j in range (M) :
            if used[i][j] == 0 :
                lst.append((i,j,0))
                used[i][j] = cnt
                tmp = 0
                while len(lst) != 0 :
                    now = lst.popleft()
                    x = now[1]
                    y = now[0]
                    tmp += 1
                    for k in range (4) :
                        if value_lst[y][x] & 1 << k == 0 : 
                            tmp_x = x + move_x_lst[k]
                            tmp_y = y + move_y_lst[k]
                            if 0 <= tmp_x < M and 0 <= tmp_y < N :
                                if used[tmp_y][tmp_x] == 0 :
                                    used[tmp_y][tmp_x] = cnt
                                    lst.append((tmp_y, tmp_x))
                size.append(tmp)
                cnt += 1
    print(cnt-1)
    print(max(size))
    visit=[[0]*M for i in range(N)]
    dq=deque()
    maximum=0
    for i in range(N):
        for j in range(M):
            if visit[i][j]==0:
                dq.append((i, j))
                visit[i][j]=1
                while dq:
                    now_i, now_j=dq.popleft()
                    for k in range(4):
                        nxt_i=now_i+move_y_lst[k]
                        nxt_j=now_j+move_x_lst[k]
                        if 0<=nxt_i<N and 0<=nxt_j<M and used[now_i][now_j]!=used[nxt_i][nxt_j]:
                            maximum=max(maximum, size[used[now_i][now_j]-1]+size[used[nxt_i][nxt_j]-1])
                        if 0<=nxt_i<N and 0<=nxt_j<M and visit[nxt_i][nxt_j]==0:
                            visit[nxt_i][nxt_j]=1
                            dq.append((nxt_i, nxt_j))
    print(maximum)
                            
BFS()
