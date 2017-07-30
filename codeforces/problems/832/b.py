
def match(pat, txt):
    diff = len(txt) - len(pat)
    if diff < -1:
        return False
    pat = pat.replace('*', '#' * (diff+1))
    if len(pat) != len(txt):
        return False
    for i in xrange(len(pat)):
        if pat[i] == '?':
            if txt[i] not in goodset:
                return False
        elif pat[i] == '#':
            if txt[i] in goodset:
                return False
        else:
            if txt[i] != pat[i]:
                return False
    return True

goodset = set(raw_input())
pat= raw_input()
n = int(raw_input())
for i in xrange(n):
    txt = raw_input()
    print "YES" if match(pat, txt) else "NO"
