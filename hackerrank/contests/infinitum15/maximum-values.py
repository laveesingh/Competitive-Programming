from math import sqrt

def phi1(x, y, z):
	return 12*(x+z)*(y+z) - 6*(x+y)**2

def phi2(x, y, z):
	return 96*sqrt(3)*x*y**2*z

def phi3(x, y, z):
	return ((3*x*z+sqrt(2)*y**2)**2)/2 + sqrt(6) - 1

def s(x, y, z, k):
	return abs(phi1(x,y,z)**2 + 6*phi1(x, y, z)*k - phi2(x, y, z) + 4*phi3(x, y, z))

def v(l, r):
	