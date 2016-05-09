import sys
 
def main():
	x = input().split(" ")
	a = x[0]
	try:
		b = x[1]
	except IndexError:
		if a == 1:
			sys.exit(1)
		else:
			for i in range(1,int(a)):
				if int(a) % i == 0:
					sys.exit(1)
				else:
					print(a)
					sys.exit(1)
 
	lis = []
 
 
	for i in range(int(a),int(b)+1):
		lis.append(str(i))
		if i == 1:
			lis.remove(str(i))
		for i in lis:
			i = int(i)
			for x in range(2, i):
				if i%x == 0:
					lis.remove(str(i))
					break
 
	for i in lis:
		print (int(i))
 
main()