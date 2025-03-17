def fac(n):
    if n <= 1:
        return 1
    return n*fac(n-1)

t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    print(int(fac(m)/(fac(m-n)*fac(n))))