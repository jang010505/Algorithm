n=int(input())
list_x=list(map(int, input().split()))
remove=int(input())
node=[[] for i in range(n)]
stack=[]
for i in range(n):
    if remove==i:
        continue
    if list_x[i]==-1:
        stack.append(i)
    else:
        if remove!=list_x[i]:
            node[list_x[i]].append(i)
cnt=0
while stack:
    now=stack.pop()
    if len(node[now])==0:
        cnt+=1
    for child in node[now]:
        if len(node[child]):
            stack.append(child)
        else:
            cnt+=1
print(cnt)
