from collections import deque
for i in range(int(input())):
    string_A, string_B, string_sum=input().split()
    visit=[[0]*250 for j in range(250)]
    len_A=len(string_A)
    len_B=len(string_B)
    q=deque()
    q.append([0, 0])
    visit[0][0]=1
    chk=False
    while q:
        q_pop=q.popleft()
        now_A=q_pop[0]
        now_B=q_pop[1]
        if now_A==len_A and now_B==len_B:
            chk=True
            break
        if now_A+1<=len_A and string_A[now_A]==string_sum[now_A+now_B] and visit[now_A+1][now_B]==0:
            q.append([now_A+1, now_B])
            visit[now_A+1][now_B]=1
        if now_B+1<=len_B and string_B[now_B]==string_sum[now_A+now_B] and visit[now_A][now_B+1]==0:
            q.append([now_A, now_B+1])
            visit[now_A][now_B+1]=1
    if chk: print("Data set %d: yes" %(i+1))
    else: print("Data set %d: no" %(i+1))
