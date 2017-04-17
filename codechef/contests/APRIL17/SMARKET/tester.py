import os, time

def tester():
    os.system("python test.py > test.in")
    os.system("./a < test.in > test1.out")
    os.system("./b < test.in > test2.out")
    f1 = open("test1.out", 'r+')
    data1 = f1.read()
    f2 = open("test2.out", 'r+')
    data2 = f2.read()
    f1.close()
    f2.close()
    print data1[:40].replace("\n",'')
    print data2[:40].replace('\n','')
    return data1 == data2

n = input("Number of times you want to test: " )
for i in xrange(n):
    if not tester():
        print "Flawed"
        break
    else:
        print "Success"
    time.sleep(1)
