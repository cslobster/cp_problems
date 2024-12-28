import math

MXT = 1001

t, k = list(map(int, input().split()))
t -= 1

c = [[0 for i in range(MXT)] for j in range(MXT)]
p = [0 for i in range(MXT)]

c[0][0] = 1
for n in range(1, MXT):
    for x in range(MXT):
        if x == 0:
            c[n][x] = 1
        else:
            c[n][x] = c[n - 1][x - 1] + c[n - 1][x]

for i in range(MXT):
    p[i] = c[t][i] / (1 << t)

prev = 0
j = 0
for i in range(k):
    ans = 0
    for j in range(math.floor(prev) + 1):
        ans += p[j]
    ans *= prev
    for x in range(j + 1, t + 1):
        ans += x * p[x]
    print(ans)
    prev = ans

print(prev + 1)