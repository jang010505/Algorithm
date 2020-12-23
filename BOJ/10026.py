from collections import deque
n=int(input())
rgb=[]
gb=[]
for i in range(n):
    x=input()
    rgb.append(list(x))
    gb.append(list(x))
    for j in range(n):
        if rgb[i][j]=='R':
            gb[i][j]='G'
cntrgb=0
for i in range(n):
    for j in range(n):
        if rgb[i][j]!='X':
            q=deque()
            q.append([i, j])
            taget=rgb[i][j]
            rgb[i][j]='X'
            cntrgb+=1
            while q:
                q_pop=q.popleft()
                I=q_pop[0]
                J=q_pop[1]
                if I+1<n and taget==rgb[I+1][J]:
                    q.append([I+1, J])
                    rgb[I+1][J]='X'
                if I-1>=0 and taget==rgb[I-1][J]:
                    q.append([I-1, J])
                    rgb[I-1][J]='X'
                if J+1<n and taget==rgb[I][J+1]:
                    q.append([I, J+1])
                    rgb[I][J+1]='X'
                if J-1>=0 and taget==rgb[I][J-1]:
                    q.append([I, J-1])
                    rgb[I][J-1]='X'
cntgb=0
for i in range(n):
    for j in range(n):
        if gb[i][j]!='X':
            q=deque()
            q.append([i, j])
            taget=gb[i][j]
            gb[i][j]='X'
            cntgb+=1
            while q:
                q_pop=q.popleft()
                I=q_pop[0]
                J=q_pop[1]
                if I+1<n and taget==gb[I+1][J]:
                    q.append([I+1, J])
                    gb[I+1][J]='X'
                if I-1>=0 and taget==gb[I-1][J]:
                    q.append([I-1, J])
                    gb[I-1][J]='X'
                if J+1<n and taget==gb[I][J+1]:
                    q.append([I, J+1])
                    gb[I][J+1]='X'
                if J-1>=0 and taget==gb[I][J-1]:
                    q.append([I, J-1])
                    gb[I][J-1]='X'
print(cntrgb, cntgb)
