for _ in range(int(input())):
    n=int(input())
    node=[0]*(n+1)
    for i in range(n-1):
        a, b=map(int, input().split())
        node[b]=a
    fir, sec=map(int, input().split())
    answer=set()
    now=fir
    answer.add(fir)
    while node[now]!=0:
        now=node[now]
        answer.add(now)
    now=sec
    if now in answer:
        print(now)
    else:
        while node[now]!=0:
            now=node[now]
            if now in answer:
                print(now)
                break
