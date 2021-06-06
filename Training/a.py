import math


ans = 1
m = 1000000007
n = 583291

for i in range(1, n + 1):
    ans = (ans * i) % m

b = 1

for i in range(1, int(n / 2) + 1):
    b = (b * 2) % m

print(ans)
print(b)
print('a')
print(ans - b)
