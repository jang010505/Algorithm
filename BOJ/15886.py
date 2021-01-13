n=int(input())
list_x=list(input())
count=1
for i in range(len(list_x)-1):
    if list_x[i]=='W' and list_x[i+1]=='E':
        count+=1
print(count)
