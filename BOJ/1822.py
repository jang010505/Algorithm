n, m=map(int, input().split())
A=list(map(int, input().split()))
B=set(map(int, input().split()))
answer=list()
for i in range(n):
    if A[i] not in B:
        answer.append(A[i])
print(len(answer))
answer.sort()
print(' '.join(map(str, answer)))
