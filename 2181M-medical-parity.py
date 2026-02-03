import sys
 
input = sys.stdin.readline
INF = 10**18
 
t = int(input())
for _ in range(t):
    x = input().strip()
    y = input().strip()
    n = len(x)
 
    # dp_prev[p] = dp at i-1 with parity p
    dp_prev = [INF, INF]
    dp_prev[0] = 0  # parity before start must be 0
 
    for i in range(n):
        dp_cur = [INF, INF]
        xi = int(x[i])
        yi = int(y[i])
 
        for prev in (0, 1):
            if dp_prev[prev] == INF:
                continue
            for cur in (0, 1):
                # x_i is determined by parity change
                expected_x = prev ^ cur
 
                cost = dp_prev[prev]
                if expected_x != xi:
                    cost += 1
                if cur != yi:
                    cost += 1
 
                if cost < dp_cur[cur]:
                    dp_cur[cur] = cost
 
        dp_prev = dp_cur
 
    print(min(dp_prev))