a, b=map(int, input().split())
if b>=20: print((b-20)/((100-b)/a)+20/((100-b)/a/2))
else: print(b/(((80+(20-b)*2)/a)/2))
