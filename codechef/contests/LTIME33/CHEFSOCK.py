j, s, m  = map(int, raw_input().split())
m -= j

m /= s

print "Unlucky Chef" if m%2 else "Lucky Chef"