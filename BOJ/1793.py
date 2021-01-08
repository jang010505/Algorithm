d=[]
d.append(1)
d.append(1)
d.append(3)
for i in range(3, 251):
    d.append(d[i-2]*2+d[i-1])
while True:
    try:
        x=int(input())
        print(d[x])
    except EOFError:
        break
