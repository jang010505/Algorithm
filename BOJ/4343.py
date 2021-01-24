def find(num):
    if parent[num]==num:
        return num
    parent[num]=find(parent[num])
    return parent[num]
def union(num1, num2):
    a=find(num1)
    b=find(num2)
    if a!=b:
        parent[a]=b
        return 1
    else:
        return 0
for _ in range(int(input())):
    s, p=map(int, input().split())
    x_list=list()
    node=list()
    for i in range(p):
        a, b=map(float, input().split())
        x_list.append((a, b))
    for i in range(p-1):
        for j in range(i+1, p):
            node.append((i, j, (((x_list[i][0]-x_list[j][0])**2+(x_list[i][1]-x_list[j][1])**2))))
    parent=[i for i in range(p)]
    node.sort(key=lambda x : x[-1])
    count=0
    for go, to, cost in node:
        answer=cost**(1/2)
        if union(go, to):
            count+=1
        if count==p-s:
            break
    print("%.2f" %answer)
