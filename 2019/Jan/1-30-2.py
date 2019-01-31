#MOOC章节三作业

# 1
s = str(input())
n = int(input())

print(s[n:] + s[:n])

# 2

import math

a = int(input())
b = int(input())

s = a * b
c = math.sqrt(a ** 2 + b ** 2)
print(round(s / c, 2))

# 3

s = list(map(str, input().split()))
print(len(s[-1]))

# 4
s = list(map(str, input().split()))
ans = 0
for i in s[0]:
    if i == s[1]:
        ans += 1
print(ans)

# 5
a = int(input())
b = int(input())
print(a + b)

# 6
Pi = 3.14159
r = int(input())
print(round(2 * Pi * r, 4), round(Pi * r * r, 4))

# 7
import math
a = int(input())
b = int(input())
c = int(input())
p = (a + b + c) / 2
S = math.sqrt(p * (p - a) * (p - b) * (p - c))
print('%.2f' % S)

# 8
a1 = int(input())
a2 = int(input())
n = int(input())
d = a2 - a1
print(a1 + (n - 1) * d)
