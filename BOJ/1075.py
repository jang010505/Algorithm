n=int(input())
f=int(input())
n=n-n%100
res=n//f
if n%f!=0: res=(res+1)*f
else: res=res*f
print("%02d"%(res%100))
