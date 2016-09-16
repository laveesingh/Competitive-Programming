import random, os

def test():
	os.system("python test.py > test.in")
	os.system("./a < test.in > test1.out")
	os.system("java JTREE < test.in > test2.out")
	data1 = open('test1.out', 'r+').read()
	data2 = open('test2.out', 'r+').read()
	if data1 == data2:
		print "Alright"
		return 1
	else:
		print "Found Flaw"
		return 0

n = input("How many number of times to run the tester")
os.system("g++ -std=c++11 JTREE.cpp -o a")
os.system("javac JTREE.java")
for _ in xrange(n):
	try:
		print _,
		if test():
			None
		else:
			break
	except KeyboardInterrupt:
		break
