n=int(raw_input())
arr=map(int,raw_input().split())
s=sum(arr)
if((s*2)%n!=0):
	print "No"
else:
	a=(s*2)/n
	a-=(n-1)*3
	if(a%2!=0):
		print "No"
	else:
		a/=2
		p=[]
		m=[]
		for i in xrange(n):
			dif=arr[i]-a;
			if(dif>0):
				p.append(dif)
			elif(dif<0):
				m.append(dif)
			a+=3
		p.sort()
		m.sort()
		p_size=len(p)
		m_size=len(m)
		i,j,k=(0,0,0)
		while(i<p_size and j<m_size):
			if(p[i]==abs(m[j])):
				i+=1
				j+=1
				k+=1
			elif(p[i]>abs(m[j])):
				p[i]+=m[j]
				j+=1
				k+=1
			else:
				m[j]+=p[i]
				i+=1
				k+=1
		print "Yes",k
