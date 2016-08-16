'''input
3 2
'''

n, m = map(float, raw_input().split())

import math

ans = math.ceil(m/n)*n
ans -= m

print int(ans)
