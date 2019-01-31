#python程序设计期末考




alist = list(map(int, input().split()))
blist = list(map(int, input().split()))

n = len(alist)
ans = 0
for i in range(n):
    ans += (alist[i] - blist[i])** 2

print(ans)





s = input()
n = len(s)

p = ''

for i in range(n):
    if s[i] <= '9' and s[i] >= '0':
        p += s[i]
    elif s[i].isalnum():
        p += s[i].lower()

if p == p[::-1]:
    print('True')
else:
    print('False')




alist = list(map(int, input().split()))
n = len(alist)

s = set()

ans = 0
for i in range(n):
    for j in range(i + 1, n):
        for k in range(j + 1, n):
            if alist[i] + alist[j] + alist[k] == 0 and (alist[i], alist[j], alist[k]) not in s:
                ans += 1
                s.add((alist[i], alist[j], alist[k]))
                s.add((alist[i], alist[k], alist[j]))
                s.add((alist[k], alist[i], alist[j]))
                s.add((alist[k], alist[j], alist[i]))
                s.add((alist[j], alist[k], alist[i]))
                s.add((alist[j], alist[i], alist[k]))

print(ans)





a = list(map(int, input().split()))
n = len(a)
b = []

for i in range(n):
    ans = 1
    for j in range(n):
        if j != i:
            ans *= a[j]
    b.append(ans)

print(b)




a = input()
n = len(a)

d = ord('E') - ord(a[-1])
if d < 0:
    d += 26

for i in range(n):
    ans = ord(a[i]) + d
    if ans > ord('Z'):
        ans -= 26
    print(chr(ans), end='')