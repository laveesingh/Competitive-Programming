
def solve(a, b, f, k):
    if b < f: return -1
    if b < (a-f): return -1
    if k > 1 and b < 2*(a-f): return -1
    if k > 2 and b < 2*f: return -1
    tank = b - f
    flag = 'f'
    fill = 0
    trips = 0
    while trips < k:
        if trips == k-1 and flag == 'b':
            if tank < f:
                fill += 1
            trips += 1
            continue
        if trips == k-1 and flag == 'f':
            if tank < a-f:
                fill += 1
            trips += 1
            continue
        trips += 1
        if flag == 'f':
            if tank >= 2*(a-f):
                tank -= 2*(a-f)
            else:
                fill += 1
                # print "on", trips, "forward filling for ", fill, " time, cur-tank", tank
                tank = b - 2*(a-f)
            flag = 'b'
        else:
            if tank >= 2*f:
                tank -= 2*f
            else:
                fill += 1
                # print "on", trips, "backward filling for ", fill, " time, cur-tank", tank
                tank = b - 2*f
            flag = 'f'
    return fill

a, b, f, k = map(int, raw_input().split())
print solve(a, b, f, k)
