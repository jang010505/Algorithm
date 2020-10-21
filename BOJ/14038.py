cnt=0
for i in range(6):
    x=input()
    if x=='W': cnt+=1
if cnt>=5: print(1)
elif cnt>=3: print(2)
elif cnt>=1: print(3)
else: print(-1)
