info=dict()
count=0
while True:
    try:
        name=input()
        count+=1
        if name in info:
            info[name]+=1
        else:
            info.update({name:1})
    except EOFError:
        break
answer=list()
for name in info.keys():
    answer.append(name)
answer.sort()
for name in answer:
    print("%s %.4f" %(name, info[name]/count*100))
