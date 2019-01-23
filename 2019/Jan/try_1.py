def work(n):
    if n == 1:
        return n;
    return work(n - 1) * n