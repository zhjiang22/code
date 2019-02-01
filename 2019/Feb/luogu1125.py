def check(n):
    if n == 0 or n == 1:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

s = input()

maxans = 0
minans = 10000

for i in s:
    maxans = max(maxans, s.count(i))
    minans = min(minans, s.count(i))

if check(maxans - minans):
    print('Lucky Word')
    print(maxans - minans)
else:
    print('No Answer')
    print(0)