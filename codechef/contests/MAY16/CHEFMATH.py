from itertools import combinations
from collections import defaultdict

cn1 = [0]*44
cn1[0] = 1
cn1[1] = 2
for i in xrange(2,44):
	cn1[i] = cn1[i-1]+cn1[i-2]

a = defaultdict(int)
for s in cn1:
	a[s] = 1

def solve(n, k):
	global a
	global cn1
	cn = [s for s in cn1 if s <= n]
	ans = 0
	if k == 1:
		if a[n]: return 1
		return 0

	elif k == 2:
		for i in xrange(len(cn)):
			if cn[i] > n: break
			for j in xrange(i,len(cn)):
				if cn[i]+cn[j] == n:
					ans += 1
				elif cn[i] +cn[j] > n:
					break
	elif k == 3:
		for i in xrange(len(cn)):
			if cn[i] > n: break
			for j in xrange(i,len(cn)):
				if cn[i] +cn[j] > n:
					break
				for k in xrange(j, len(cn)):
					if cn[i]+cn[j]+cn[k] == n:
						ans += 1
					if cn[i]+cn[j]+cn[k] > n:
						break
	elif k == 4:
		for i in xrange(len(cn)):
			if cn[i] > n: break
			for j in xrange(i,len(cn)):
				if cn[i] +cn[j] > n:
					break
				for k in xrange(j, len(cn)):
					if cn[i]+cn[j]+cn[k] > n:
						break
					for l in xrange(k, len(cn)):
						if cn[i]+cn[j]+cn[k]+cn[l] == n:
							ans += 1
						if cn[i]+cn[j]+cn[k]+cn[l] > n:
							break
	elif k == 5:
		for i in xrange(len(cn)):
			if cn[i] > n: break
			for j in xrange(i,len(cn)):
				if cn[i] +cn[j] > n:
					break
				for k in xrange(j, len(cn)):
					if cn[i]+cn[j]+cn[k] > n:
						break
					for l in xrange(k, len(cn)):
						if cn[i]+cn[j]+cn[k]+cn[l] > n:
							break
						for m in xrange(l, len(cn)):
							if cn[i]+cn[j]+cn[k]+cn[l]+cn[m] == n:
								ans += 1
							if cn[i]+cn[j]+cn[k]+cn[l]+cn[m] > n:
								break

	elif k == 6:
		# cn = [s for s in cn if s <= n]
		for i in xrange(len(cn)):
			if cn[i] > n: break
			for j in xrange(i,len(cn)):
				if cn[i] +cn[j] > n:
					break
				for k in xrange(j, len(cn)):
					if cn[i]+cn[j]+cn[k] > n:
						break
					for l in xrange(k, len(cn)):
						if cn[i]+cn[j]+cn[k]+cn[l] > n:
							break
						for m in xrange(l, len(cn)):
							if cn[i]+cn[j]+cn[k]+cn[l]+cn[m] > n:
								break
							for nn in xrange(m, len(cn)):
								if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn] == n:
									ans += 1
								if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn] > n:
									break
	elif k==7:
		# if n <= 100:
		# 	cn = [s for s in cn[:10]]
		for i in xrange(len(cn)):
			if cn[i] > n: break
			for j in xrange(i,len(cn)):
				if cn[i] +cn[j] > n:
					break
				for k in xrange(j, len(cn)):
					if cn[i]+cn[j]+cn[k] > n:
						break
					for l in xrange(k, len(cn)):
						if cn[i]+cn[j]+cn[k]+cn[l] > n:
							break
						for m in xrange(l, len(cn)):
							if cn[i]+cn[j]+cn[k]+cn[l]+cn[m] > n:
								break
							for nn in xrange(m, len(cn)):
								if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn] > n:
									break
								for o in xrange(nn, len(cn)):
									if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn]+cn[o] == n:
										ans += 1
									if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn]+cn[o] > n:
										break
	elif k == 8:
		# if n <= 100:
		# 	cn = [s for s in cn[:10]]
		for i in xrange(len(cn)):
			if cn[i] > n: break
			for j in xrange(i,len(cn)):
				if cn[i] +cn[j] > n:
					break
				for k in xrange(j, len(cn)):
					if cn[i]+cn[j]+cn[k] > n:
						break
					for l in xrange(k, len(cn)):
						if cn[i]+cn[j]+cn[k]+cn[l] > n:
							break
						for m in xrange(l, len(cn)):
							if cn[i]+cn[j]+cn[k]+cn[l]+cn[m] > n:
								break
							for nn in xrange(m, len(cn)):
								if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn] > n:
									break
								for o in xrange(nn, len(cn)):
									if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn]+cn[o] > n:
										break
									for p in xrange(o,len(cn)):
										if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn]+cn[o]+cn[p] == n:
											ans += 1
										if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn]+cn[o]+cn[p] > n:
											break
	elif k == 9:
		# if n <= 100:
		# 	cn = [s for s in cn[:10]]
		for i in xrange(len(cn)):
			if cn[i] > n: break
			for j in xrange(i,len(cn)):
				if cn[i] +cn[j] > n:
					break
				for k in xrange(j, len(cn)):
					if cn[i]+cn[j]+cn[k] > n:
						break
					for l in xrange(k, len(cn)):
						if cn[i]+cn[j]+cn[k]+cn[l] > n:
							break
						for m in xrange(l, len(cn)):
							if cn[i]+cn[j]+cn[k]+cn[l]+cn[m] > n:
								break
							for nn in xrange(m, len(cn)):
								if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn] > n:
									break
								for o in xrange(nn, len(cn)):
									if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn]+cn[o] > n:
										break
									for p in xrange(o,len(cn)):
										if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn]+cn[o]+cn[p] > n:
											break
										for q in xrange(p,len(cn)):
											if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn]+cn[o]+cn[p]+cn[q] == n:
												ans += 1
											if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn]+cn[o]+cn[p]+cn[q] > n:
												break
	elif k == 10:
		# if n <= 100:
		# 	cn = [s for s in cn[:10]]
		for i in xrange(len(cn)):
			if cn[i] > n: break
			for j in xrange(i,len(cn)):
				if cn[i] +cn[j] > n:
					break
				for k in xrange(j, len(cn)):
					if cn[i]+cn[j]+cn[k] > n:
						break
					for l in xrange(k, len(cn)):
						if cn[i]+cn[j]+cn[k]+cn[l] > n:
							break
						for m in xrange(l, len(cn)):
							if cn[i]+cn[j]+cn[k]+cn[l]+cn[m] > n:
								break
							for nn in xrange(m, len(cn)):
								if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn] > n:
									break
								for o in xrange(nn, len(cn)):
									if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn]+cn[o] > n:
										break
									for p in xrange(o,len(cn)):
										if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn]+cn[o]+cn[p] > n:
											break
										for q in xrange(p,len(cn)):
											if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn]+cn[o]+cn[p]+cn[q] > n:
												break
											for r in xrange(q, len(cn)):
												if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn]+cn[o]+cn[p]+cn[q]+cn[r] == n:
													ans += 1
												if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn]+cn[o]+cn[p]+cn[q]+cn[r] > n:
													break
	return ans


def I():
	return map(int, raw_input().split())

for _ in xrange(input()):
	print solve(*I())


# for s in combinations(a,10):
#  if sum(s) == 89 and not vis[hash(tuple(s))]:
#   print tuple(s)
#   vis[hash(tuple(s))] = 1
#   ans += 1


# for i in xrange(len(cn)):
# 	if cn[i] > n: break
# 	for j in xrange(i,len(cn)):
# 		if cn[i] +cn[j] > n:
# 			break
# 		for k in xrange(j, len(cn)):
# 			if cn[i]+cn[j]+cn[k] > n:
# 				break
# 			for l in xrange(k, len(cn)):
# 				if cn[i]+cn[j]+cn[k]+cn[l] > n:
# 					break
# 				for m in xrange(l, len(cn)):
# 					if cn[i]+cn[j]+cn[k]+cn[l]+cn[m] > n:
# 						break
# 					for nn in xrange(m, len(cn)):
# 						if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn] > n:
# 							break
# 						for o in xrange(nn, len(cn)):
# 							if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn]+cn[o] > n:
# 								break
# 							for p in xrange(o,len(cn)):
# 								if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn]+cn[o]+cn[p] > n:
# 									break
# 								for q in xrange(p,len(cn)):
# 									if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn]+cn[o]+cn[p]+cn[q] > n:
# 										break
# 									for r in xrange(q, len(cn)):
# 										if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn]+cn[o]+cn[p]+cn[q]+cn[r] == n:
# 											ans += 1
# 										if cn[i]+cn[j]+cn[k]+cn[l]+cn[m]+cn[nn]+cn[o]+cn[p]+cn[q]+cn[r] > n:
# 											break

