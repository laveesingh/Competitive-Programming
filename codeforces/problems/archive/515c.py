
store = {
    "9": "2337",
    "8": "2227",
    "6": "35",
    "4": "223",
    "1": "",
    "0": "",
}

n = input()
a = raw_input()

for s in store:
    a = a.replace(s, store[s])
a = list(a)
a.sort(reverse=1)
print ''.join(a)
