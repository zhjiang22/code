import sys

def ok(c):
    if c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u':
        return True
    else:
        return False

a = input()
b = input()

if len(a) != len(b):
    print('No')
    sys.exit(0)

n = len(a)
for i in range(n):
    if ok(a[i]) != ok(b[i]):
        print('No')
        sys.exit(0)

print('Yes')
