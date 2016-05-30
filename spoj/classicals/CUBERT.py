from math import pow


def icbrt(n):
    if n.bit_length() < 1024:  # float(n) safe from overflow
        a = int(round(n**(1/3.)))
        a = (2*a + n//a**2)//3  # Ensure a >= floor(cbrt(n)).
    else:
        a = 1 << -(-n.bit_length()//3)

    while True:
        d = n//a**2
        if a <= d:
            return a
        a = (2*a + d)//3

def cbrt_to_ten_places(n):
    
    a = icbrt(n * 10**30)
    q, r = divmod(a, 10**10)
    return "{}.{:010d}".format(q, r)



def checksum(a):
	ans = 0
	for s in a:
		if s != '.':
			ans += int(s)
	return ans

def solve():
	t = int(raw_input())
	while t:
		t -= 1
		n = raw_input().strip()
		if not n:
			t += 1
			continue
		n = int(n)
		ans = cbrt_to_ten_places(n)
		csum = checksum(str(ans))
		print csum%10,ans

solve()