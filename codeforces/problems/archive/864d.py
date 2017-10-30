from collections import Counter, defaultdict

n = input()
arr = map(int, raw_input().split())
cnt = Counter(arr)
done = defaultdict(int)
cur = 1
changes = 0
i = 0
while i < n:
    if cnt[cur] > 0:
        cur += 1
        # done[cur] = 1
    else:
        if cnt[arr[i]] == 1 or (not done[arr[i]] and cur > arr[i]):
            done[arr[i]] = 1
            i += 1
        # elif done[arr[i]] or (not done[arr[i]] and cur < arr[i]):
        else:
            cnt[arr[i]] -= 1
            arr[i] = cur
            cnt[arr[i]] += 1
            done[arr[i]] = 1
            cur += 1
            changes += 1
            i += 1
    # print "i:", i, "cur:", cur, "done:", done
print changes
for s in arr:
    print s,
print
