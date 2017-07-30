
import os

def test():
	os.system("python test.py > test.in")
	os.system("python check.py < test.in > test1.out")
	os.system("./a < test.in > test2.out")
	data1 = open("test1.out", "r+").read()
	data2 = open("test2.out", "r+").read()
	return data1 == data2

n = input("How many times do you want to run the test?")
for _ in xrange(n):
	if test():
		print _, "Alright"
	else:
		print "Found flaw"
		break
