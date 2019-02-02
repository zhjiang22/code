import sys
a = input().rstrip()
b = input().rstrip()
c = input().rstrip()

n = len(a)

s = {}
s2 = {}

for i in range(n):
    if a[i] in s.keys():
        if b[i] != s[a[i]]:
            print('Failed')
            sys.exit(0)
    elif b[i] in s2.keys():
        if a[i] != s2[b[i]]:
            print('Failed')
            sys.exit(0)
    else:
        s[a[i]] = b[i]
        s2[b[i]] = a[i]

if len(s) != 26:
    print('Failed')
else:
    for i in c:
        print(s[i], end='')