from math import sqrt

def primes_upto_sqrt(n):
	l = int(sqrt(n)+1.5)
	primes = [0]*l
	primes[0] = 1
	primes[1] = 1
	for i in xrange(4, l, 2): primes[i] = 1
	for i in xrange(3, int(sqrt(l)+1.5), 2):
		if not primes[i]:
			for j in xrange(i*i, l, i):
				primes[j] = 1
	return [i for i in xrange(len(primes)) if not primes[i]]



def segmented_sieve(m, n):
	global output
	primes = [0]*(n-m)
	if m < 2: primes[0] = 1
	sqprime = primes_upto_sqrt(n) # Primes upto square root of upper limit
	for s in sqprime:
		#print "S: ",s,
		start = (m/s)*s + s
		if not m%s:
			start = m
		if s == start: start += s
		#print "start:",start,"erasing",
		for i in xrange(start, n, s):
			#print i,
			primes[i-m] = 1
		#print
	for i in xrange(len(primes)):
		if not primes[i] :
			#print i+m
			output += str(i+m)+"\n"


inputs = []
output = ""
for _ in xrange(input()):
	inputs.append(map(int, raw_input().split()))

for m, n in inputs[:-1]:
	segmented_sieve(m, n+1)
	output += "\n"
	#print
segmented_sieve(inputs[-1][0], inputs[-1][1]+1)
#print "Opening a file..."
# f = open("out2.txt", "w")
# #print "File opened!"
# f.write(output[:-1])
# f.close()
print output[:-1]