
import os

def test():
	os.system("python test.py > test.in")
	os.system("python inverse-rmq.py < test.in > test1.out")
	os.system("python inv.py < test.in > test2.out")
	data1 = open('test1.out', 'r+').read()
	data2 = open('test2.out', 'r+').read()
	if data1 != data2:
		return 0
	return 1

n = input("NO of times you want to the rtest")
for _ in xrange(n):
	if test() == 0:
		print "Flaw found"
		break
	else:
		print "Alright"
