n, m, a = map(float, raw_input().split())
import math
ans = math.ceil(n/a)*math.ceil(m/a)
print int(ans)