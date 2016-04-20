

def solve(n, o, i):
	global weights, nit, ox
	if (n <= 0 and o <= 0):
		return 0
	if i < 0: return 0
	return min(weights[i]+solve(n-nit[i], o-ox[i], i-1), solve(n, o, i-1))
