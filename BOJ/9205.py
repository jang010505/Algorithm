from collections import deque
for _ in range(int(input())):
    store_cnt=int(input())
    store=[]
    home_x, home_y=map(int, input().split())
    for i in range(store_cnt):
        store_x, store_y=map(int, input().split())
        store.append([store_x, store_y])
    fast_x, fast_y=map(int, input().split())
    store.append([fast_x, fast_y])
    q=deque()
    q.append([home_x, home_y])
    chk=1
    while q:
        q_pop=q.popleft()
        x=q_pop[0]
        y=q_pop[1]
        if fast_x==x and fast_y==y:
            print("happy")
            chk=0
            break
        for i in store:
            xl=abs(x-i[0])
            yl=abs(y-i[1])
            if xl+yl<=1000:
                q.append([i[0], i[1]])
                store.remove(i)
    if chk==1:
        print("sad")
