def cal(n):
    ans = 1
    res = 3
    while n:
        if n % 2:
            ans = (ans * res) % 1000000007
        res = (res * res) % 1000000007
        n //= 2
    return ans
n = int(input())
ans = cal(n+1)
if ans % 2:
    ans = (ans - 1) // 2
else:
    ans = (ans - 1 + 1000000007) // 2
print(ans)