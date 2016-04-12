german = {'ä':100, 'Ä':100, 'é':50, 'ö':100, 'Ö':100, 'ü':50, 'Ü':100, 'ß':100}
french = {'è':50, 'à':50, 'é':50, 'œ':50,'Ç':100, 'û':100, 'ô':100,'î':100,'ê':100,'â':100,'Æ':100,'Œ':100}
spanish = {'ñ':100,'á':50,'é':50,'í':50,'ü':50, '¡':100, '¿':200}
g=0
f=0
s=0
A=raw_input()
# for i in range(len(A)):
#     #print A[i]
#     if A[i] in german.keys():
# 		g+=german[A[i]]
#     elif A[i] in french.keys():
# 		f+=french[A[i]]
#     elif A[i] in spanish.keys():
# 		s+=spanish[A[i]]
for x in A:
	print x,
	if x in german:
		print 'g'
		g += german[x]
	if x in french:
		print 'f'
		f += french[x]
	if x in spanish:
		print 's'
		s += spanish[x]
	
		
#print g,f,s
if (g==0 and s==0 and f==0):
	print "English"
elif (g>=f and g>=s):
	print "German"
elif (f>=g and f>=s):
	print "French"
else:
	print "Spanish"