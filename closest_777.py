n = int(input())
a = [0, 1, 1]
if n <= 2:
    print(a[n])
else:
    for i in range(n - 1):
        a.append(sum(a[-3:]))
    print(a[-1])