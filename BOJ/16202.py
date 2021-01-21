def find(num):
    if parent[num]==num:
        return num
    else:
        parent[num]=find(parent[num])
        return parent[num]
def union(num1, num2):
    a=find(num1)
    b=find(num2)
    if a!=b:
        parent[b]=a
def parentFind(num1, num2):
    if find(num1)==find(num2):
        return 1
    else:
        return 0
n, m, k=map(int, input().split())
node=list()
for i in range(m):
    x, y=map(int, input().split())
    node.append((x, y, i+1))
answer=0
node.sort(key=lambda x : x[-1])
for _ in range(k):
    parent=[i for i in range(n+1)]
    answer=0
    answer_list=[]
    for x, y, cost in node:
        if parentFind(x, y)==0:
            union(x, y)
            answer+=cost
            answer_list.append((x, y, cost))
    chk=1
    for i in range(1, n):
        if parentFind(i, i+1)==0:
            chk=0
            break
    if chk: print(answer, end=' ')
    else: print(0, end=' ')
    node.remove (answer_list.pop(0))
