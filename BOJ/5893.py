x=input()
res=0
if x=='0': print(0)
else:
    for i in range(len(x)):
        if x[len(x)-1-i]=='1':
            res+=2**i
    res*=17
    print(bin(res)[2:])
