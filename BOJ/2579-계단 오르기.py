n = int(input())
stairs = [0] + [int(input()) for _ in range(n)] + [0]
cache = [0] * (n+2)
cache[1] = stairs[1]
cache[2] = cache[1] + stairs[2]

for i in range(3, n+1):
    cache[i] = max(cache[i-2], cache[i-3] + stairs[i-1]) + stairs[i]
print(cache[n])