import sys
while True:
    s=list (sys.stdin.readline())
    if s[0]==s[1]==s[2]=='*': exit()
    s.reverse()
    del s[0]
    for i in range(len(s)):
        print(s[i],end='')
    print()
