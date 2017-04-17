import random
import os
import time

def test():
    choices = [0]*4
    choices[0] = random.randint(1,10)
    choices[1] = random.randint(1,100)
    choices[2] = random.randint(1,10**6)
    choices[3] = random.randint(1,10**12)
    choice = random.choice(choices)
    f = open('test.in', 'w+')
    f.write(str(choice) + " " + str(choice) + "\n")
    f.close()
    os.system("./a < test.in > test1.out")
    os.system("./b < test.in > test2.out")
    data1 = open("test1.out", 'r+').read()
    data2 = open("test2.out", 'r+').read()
    
    print choice,'\n',data1, data2
    return data1 == data2

n = input("Testing times: ")
for i in xrange(n):
    if not test():
        print "Flaw Found"
        break
    time.sleep(1)
