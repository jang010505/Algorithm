a, b, c, d ,e=map(int, input().split())
if a%b!=0:
    if a%d!=0: print(min((a//d+1)*e, (a//b+1)*c))
    else: print(min((a//d)*e, (a//b+1)*c))
else:
    if a%d!=0: print(min((a//d+1)*e, (a//b)*c))
    else: print(min((a//d)*e, (a//b)*c))
