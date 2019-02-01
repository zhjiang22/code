s = input()
n = len(s)
a = []
a.append(s[0])

ans = 0

for i in range(1, n):
    if a:
        cur = a.pop()
        if cur == s[i]:
            ans += 1
            continue
        else:
            a.append(cur)
            a.append(s[i])
    else:
        a.append(s[i])

if ans % 2:
    print('Yes')
else:
    print('No')