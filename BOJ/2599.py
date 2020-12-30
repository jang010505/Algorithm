n=int(input())
x=[]
for i in range(3):
    x.append(list(map(int, input().split())))
for i in range(x[0][0]):
    a2=x[0][0]-i
    b1=n-x[2][0]-x[2][1]-i
    b2=x[1][0]-b1
    c1=x[0][1]-b1
    c2=x[2][0]-c1
    if a2>=0 and b1>=0 and b2>=0 and c1>=0 and c2>=0:
        print(1)
        print(i, a2)
        print(b1, b2)
        print(c1, c2)
        exit()
print(0)
