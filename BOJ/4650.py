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
    else:
        return 0

n=int(input())
while n!=0:
    parent=[i for i in range(n+1)]
    node=list()
    answer_sum=0
    for i in range(n-1):
        list_x=list(input().split())
        for j in range(2, len(list_x), 2):
            node.append((ord(list_x[0])-64, ord(list_x[j])-64, int(list_x[j+1])))
    node.sort(key=lambda x : x[-1])
    for i in range(len(node)):
        if findParent(node[i][0], node[i][1])==0:
            union(node[i][0], node[i][1])
            answer_sum+=node[i][2]
    print(answer_sum)
    n=int(input())
