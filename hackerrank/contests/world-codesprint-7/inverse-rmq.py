n = input()

def build(node, a, b, st, en):
	if st == en:
		b[node] = a[st]
		return
	build(2*node, a, b, st, (st+en)/2)
	build(2*node+1, a, b, (st+en)/2 + 1, en)
	b[node] = min(b[2*node], b[2*node+1])

T = map(int, raw_input().split())

a = sorted((set(T)))
# print "a:",a

if len(a) != n:
	print "NO"
else:
	final_T = [0]*(2*n)
	build(1, a, final_T, 0, n-1)
	final_T = final_T[1:]
	if sorted(T) != sorted(final_T):
		print "NO"
	else:
		print "YES"
		for s in final_T:
			print s,
		print
