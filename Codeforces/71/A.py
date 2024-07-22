def solve():
    n = int(input())
    l = list(map(int, input().split()))
    print(sum(l))


test = int(input())
for _ in range(test):
    solve()
