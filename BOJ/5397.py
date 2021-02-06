for _ in range(int(input())):
    left=list()
    right=list()
    info=input()
    for i in range(len(info)):
        if info[i]=='<':
            if left:
                right.append(left.pop())
        elif info[i]=='>':
            if right:
                left.append(right.pop())
        elif info[i]=='-':
            if left:
                left.pop()
        else:
            left.append(info[i])
    left.extend(reversed(right))
    print(''.join(left))
