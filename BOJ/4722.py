def find(num):
    if parent[num]==num:
        return num
    else:
        parent[num]=find(parent[num])
        return parent[num]
def union(num1, num2):
    num1=find(num1)
    num2=find(num2)
    if num1!=num2:
        parent[num1]=num2
        return 1
    else:
        return 0
def dist(num1, num2):
    return (num1*num1+num2*num2)**(1/2)
n=int(input())
while n!=0:
    x_list=list()
    answer=0
    node=list()
    parent=[i for i in range(n)]
    for i in range(n):
        x_list.append(list(map(int, input().split())))
    for i in range(n-1):
        for j in range(i, n):
            node.append((i, j, dist(x_list[i][0]-x_list[j][0], x_list[i][1]-x_list[j][1])))
    node.sort(key=lambda x : x[-1])
    for go, to, cost in node:
        if union(go, to):
            answer+=cost
    print("%.2f" %(answer))
    n=int(input())
