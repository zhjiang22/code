global n, m
global root
global edge
global fa

def init():
    global n, m, root, edge, fa
    n = int(input())
    m = int(input())
    edge = {}
    fa = {}
    for i in range(1, n + 1):
        fa[i] = i
    root = int(input())
    for i in range(m):
        u, v, w = map(int, input().split())
        edge[(u, v)] = w

def getfather(x):
    if fa[x] == x:
        return x
    fa[x] = getfather(fa[x])
    return fa[x]

def work():
    global edge
    Edge = sorted(edge, key=edge.__getitem__)
    ans = 0
    cnt = 0
    for i in range(m):
        u = Edge[i][0]
        v = Edge[i][1]
        w = edge[Edge[i]]
        if getfather(u) == getfather(v):
            continue
        ans = max(ans, w)
        cnt += 1
        fa[getfather(u)] = getfather(v)
        if cnt == n - 1:
            break;
    print(ans)
init()
work()