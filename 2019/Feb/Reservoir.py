import random

a = []
k = int(input())
for i in range(k):
    a.append(int(input()))

while True:
    x = int(input())
    if x == -1:
        break
    j = random.randint(1, i)
    if j <= k:
        a[j] = x

print(a)