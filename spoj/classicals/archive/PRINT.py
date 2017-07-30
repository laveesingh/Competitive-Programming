from math import sqrt
import sys

def primes_upto_sqrt(n):
	l = int(sqrt(n) + 1.5)
	primes = [1] * l
	primes[0] = 0
	primes[1] = 0
	for i in xrange(4, l, 2): primes[i] = 0
	for i in xrange(3, int(sqrt(l)+ 1.5), 2): 
		
		if primes[i]:
			for j in xrange(i*i, l, i):
				primes[j] = 0
	return [i for i in xrange(len(primes)) if primes[i]]

def segmented_sieve(m, n):
	global output
	primes = [1] * (n-m)

	if m < 2: primes[0] = 0
	sqprime = primes_upto_sqrt(n) # primes upto square root of upper limit
	#print "sqprime: ", sqprime
	for s in sqprime:
		start = (m/s) * s + s
		if not m%s:
			start = m
		if s == start: start += s

		for i in xrange(start, n, s):
			primes[i - m] = 0
	#print "primes: ", primes
	for i in xrange(len(primes)):
		if primes[i]:
			output += str(i + m) + "\n"

output = ""

t = int(sys.stdin.readline())

for i in xrange(t):
	m, n = map(int, sys.stdin.readline().split())
	segmented_sieve(m, n+1)

sys.stdout.write(output)