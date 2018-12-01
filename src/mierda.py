from math import gcd
n = int(input())
for i in range(n):
    a, b, c, d, k = [int(x) for x in input().strip().split(" ")]
    r = 0
    for x in range(a, b + 1):
        for y in range(x, d + 1):
            if(gcd(x, y) == k):
                r += 1
    print("{}".format(r))
