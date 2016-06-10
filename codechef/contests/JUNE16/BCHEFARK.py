
def solve(a, n, k):
	store = set()
	if k == 1:
		for i in xrange(n):
			a[i] = -a[i]
			store.add(tuple(a))
			a[i] = -a[i]
		return len(store)
	if k == 2:
		for i in xrange(n):
			for j in xrange(n):
				a[i] = -a[i]
				a[j] = -a[j]
				store.add(tuple(a))
				a[i] = -a[i]
				a[j]  = -a[j]
		return len(store)

	if k == 3:
		for i in xrange(n):
			for j in xrange(n):
				for k in xrange(n):
					a[i] = -a[i]
					a[j] = -a[j]
					a[k]  = -a[k]
					store.add(tuple(a))
					a[i] = -a[i]
					a[j]  = -a[j]
					a[k]  = -a[k]
		return len(store)

	if k == 4:
		for i in xrange(n):
			for j in xrange(n):
				for k in xrange(n):
					for l in xrange(n):
						a[i] = -a[i]
						a[j] = -a[j]
						a[k]  = -a[k]
						a[l] = -a[l]
						store.add(tuple(a))
						a[i] = -a[i]
						a[j]  = -a[j]
						a[k]  = -a[k]
						a[l] = -a[l]
		return len(store)
	if k == 5:
		for i in xrange(n):
			for j in xrange(n):
				for k in xrange(n):
					for l in xrange(n):
						for m in xrange(n):
							a[i] = -a[i]
							a[j] = -a[j]
							a[k]  = -a[k]
							a[l] = -a[l]
							a[m] = -a[m]
							store.add(tuple(a))
							a[i] = -a[i]
							a[j]  = -a[j]
							a[k]  = -a[k]
							a[l] = -a[l]
							a[m] = -a[m]
		return len(store)
	if k == 6:
		for i in xrange(n):
			for j in xrange(n):
				for k in xrange(n):
					for l in xrange(n):
						for m in xrange(n):
							for o in xrange(n):
								a[i] = -a[i]
								a[j] = -a[j]
								a[k]  = -a[k]
								a[l] = -a[l]
								a[m] = -a[m]
								a[o] = -a[o]
								store.add(tuple(a))
								a[i] = -a[i]
								a[j]  = -a[j]
								a[k]  = -a[k]
								a[l] = -a[l]
								a[m] = -a[m]
								a[o] = -a[o]
		return len(store)
	if k == 7:
		for i in xrange(n):
			for j in xrange(n):
				for k in xrange(n):
					for l in xrange(n):
						for m in xrange(n):
							for o in xrange(n):
								for p in xrange(n):
									a[i] = -a[i]
									a[j] = -a[j]
									a[k]  = -a[k]
									a[l] = -a[l]
									a[m] = -a[m]
									a[o] = -a[o]
									a[p] = -a[p]
									store.add(tuple(a))
									a[i] = -a[i]
									a[j]  = -a[j]
									a[k]  = -a[k]
									a[l] = -a[l]
									a[m] = -a[m]
									a[o] = -a[o]
									a[p] = -a[p]
		return len(store)
I = lambda : map(int, raw_input().split())
n, k = I()
a = I()
print solve(a, n, k)