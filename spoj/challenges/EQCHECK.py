import re,fractions as f
for _ in range(input()):
 x,y,c=map(int,re.findall('\d+',raw_input()));print["yes","no"][c%f.gcd(x,y)!=0]
