
def dist(a, b):
    return abs(b - a)


def solve(keys, persons, office):
    keys.sort()
    persons.sort()
    mintime = 10**19
    for i in xrange(len(keys) - len(persons) + 1):
        maxtime = 0
        for j in xrange(len(persons)):
            person = persons[j]
            key = keys[i+j]
            time = dist(person, key) + dist(office, key)
            maxtime = max(maxtime, time)
        mintime = min(mintime, maxtime)
    return mintime

I = lambda : map(int, raw_input().split())

n, k, p = I()
persons = I()
keys = I()

print solve(keys, persons, p)
