n=int(input())
x_dict=dict()
for i in range(n):
    name, info=input().split()
    if name in x_dict:
        if info=="leave":
            x_dict[name]=0
        else:
            x_dict[name]=1
    else:
        if info=="leave":
            x_dict.update({name:0})
        else:
            x_dict.update({name:1})
answer=list()
for name in x_dict.keys():
    if x_dict[name]:
        answer.append(name)
answer.sort()
answer.reverse()
for name in answer:
    print(name)
        
