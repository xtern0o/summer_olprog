n = int(input())
bridges = [list(map(int, input().split())) for _ in range(n)]    
input()
color = list(map(int, input().split()))
g = [[] for _ in range(n)]

for i in range(n):
    for j in range(n):
        if bridges[i][j] == 1:
            g[i].append(j)

bad = 0
for i in range(n):
    for j in g[i]:
        if color[i] != color[j]:
            bad += 1

print(bad // 2)