
class DistinguishableSetDiv2:

	def __init__(self):
		None

	def count(self, answer):
		n = len(answer)
		m = len(answer[0])
		count = 0
		for i in xrange(2**m):
			curset = []
			bini = bin(i)[2:].zfill(m)
			for j in xrange(len(bini)):
				if bini[j] == '1':
					curset.append(j)
			dset = []
			for ans in answer:
				curans = []
				for s in curset:
					curans .append(ans[s])
				curans = ''.join(curans)
				dset.append(curans)
			if len(dset) == len(set(dset)):
				count += 1
			

		return count

a = DistinguishableSetDiv2()
answer = raw_input().split()
print a.count(answer)