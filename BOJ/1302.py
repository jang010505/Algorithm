n=int(input())
info=dict()
for i in range(n):
    name=input()
    if name in info:
        info[name]+=1
    else:
        info.update({name:1})
max_count=0
answer=''
for name in info.keys():
    if max_count==info[name]:
        if answer>name:
            answer=name
    elif max_count<info[name]:
        max_count=info[name]
        answer=name
print(answer)
