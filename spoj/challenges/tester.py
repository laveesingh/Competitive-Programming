import os

for i in xrange(50001):
	os.system("echo '%d\n' > test.in"%(i))
	os.system("python check.py < test.in > test1.out")
	os.system("python NUMWORD.py < test.in > test2.out")
	data1 = open("test1.out", "r+").read()
	data2 = open("test2.out", "r+").read()
	if data1 != data2:
		print "Found flaw"
		break
	else:
		print "Alright"