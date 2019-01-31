alist = list(map(int, input().split()))
n = len(alist)
for i in range(n):
    if alist[i] % 2:
        alist[i] = alist[i]** 2
    else:
        alist[i] //= 2
print(sorted(alist))