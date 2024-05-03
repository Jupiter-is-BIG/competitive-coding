def extended_bottom_up_cut_rod(p, n):
    r = [0] * (n + 1)
    s = [0] * (n + 1)
    for j in range(1, n + 1):
        q = float("-inf")
        for i in range(1, j + 1):
            if q < p[i - 1] + r[j - i]:
                q = p[i - 1] + r[j - i]
                s[j] = i
        r[j] = q
    return r, s


def print_cut_rod_solution(p, n):
    if n <= 0:
        print("Max Profit: 0")
        print("n must be at least 1 to get division scheme for optimal profit")
        return
    r, s = extended_bottom_up_cut_rod(p, n)
    print(f"Max Profit: {r[-1]}")
    print("Division for optimal profit:")
    while n > 0:
        print(s[n], end=" ")
        n -= s[n]
    print()


n = int(input())
p = list(map(int, input().split()))
print_cut_rod_solution(p, n)
