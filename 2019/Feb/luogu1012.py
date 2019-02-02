n = int(input())
slist = list(map(str, input().split()))

for i in range(n):
    for j in range(i + 1, n):
        if slist[i] + slist[j] < slist[j] + slist[i]:
            slist[i], slist[j] = slist[j], slist[i]

for i in slist:
    print(i, end='')