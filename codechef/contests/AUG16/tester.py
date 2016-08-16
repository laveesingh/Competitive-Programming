import os, time

def test():
	os.system("python SHAIKHGN.test > test.in")
	print "Input written",
	os.system("python SHAIKHGN.py < test.in > test1.out")
	print "First test done",
	os.system("python SHAIKHGNbk.py < test.in > test2.out")
	print "Second test done",
	data1 = open("test1.out", 'r+').read()
	data2 = open("test2.out", 'r+').read()
	if data1 == data2:
		print "Same Same"
		# time.sleep(1)
		return 0
	else:
		print "Got the flaw"
		return 1

n = input()

for _ in xrange(n):
	if test():
		break

