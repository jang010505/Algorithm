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
def findParent(num1, num2):
    a=find(num1)
    b=find(num2)
    if a==b:
        return 1
    elif a!=b:
        return 0
n, m=map(int, input().split())
while n!=0 or m!=0:
    parent=[i for i in range(n+1)]
    node=[]
    sum_elc=0
    for i in range(m):
        a, b, c=map(int, input().split())
        node.append((a, b, c))
        sum_elc+=c
    node.sort(key = lambda x : x[-1])
    answer=[]
    for i in range(m):
        if findParent(node[i][0], node[i][1])==0:
            union(node[i][0], node[i][1])
            answer.append(node[i][2])
    print(sum_elc-sum(answer))
    n, m=map(int, input().split())
