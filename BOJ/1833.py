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
n=int(input())
parent=[i for i in range(n+1)]
node=[]
answer_sum=0
answer_cnt=0
answer_list=[]
for i in range(n):
    list_x=list(map(int, input().split()))
    for j in range(i+1, n):
        if list_x[j]<0:
            union(i, j)
            answer_sum-=list_x[j]
        else:
            node.append((i, j, list_x[j]))
node.sort(key = lambda x : x[-1])
for i in range(len(node)):
    if findParent(node[i][0], node[i][1])==0:
        union(node[i][0], node[i][1])
        answer_cnt+=1
        answer_list.append((node[i][0], node[i][1]))
        answer_sum+=node[i][2]
print(answer_sum, answer_cnt)
for i, j in answer_list:
    print(i+1, j+1)
