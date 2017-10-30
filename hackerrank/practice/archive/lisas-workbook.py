
def eachstart(a, k):
	p = 0
	es = []
	es.append(1)
	for s in a:
		p += s/k
		if s%k:
			p += 1
		es.append(p+1)
	return es[:-1]

n, k = map(int, raw_input().split())
a = map(int, raw_input().split())
eachs = eachstart(a, k)
for i, s in enumerate(eachs[:-1]):
	
	for page in pages:
