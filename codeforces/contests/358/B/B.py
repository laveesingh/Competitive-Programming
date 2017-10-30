
n = input()
init = []
for i in xrange(n):
    init.append(raw_input())

astring = raw_input()
found_heart = False
found_angle = False
lindex = 0
windex = 0
for i in xrange(len(astring)):
    if found_heart:
        if len(init) == lindex: break
        if astring[i] == init[lindex][windex]:
            windex += 1
        if windex == len(init[lindex]):
            windex = 0
            lindex += 1
            found_heart = False
            found_angle = False
    else:
        if found_angle:
            if astring[i] == '3':
                found_heart = True
        elif astring[i] == '<':
            found_angle = True
print "yes" if (len(init) == lindex and found_heart) else "no"
