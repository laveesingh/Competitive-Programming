for i in range(input()):
 w=raw_input();a=w.split();r=t=0;d={"on":1,"el":11,"tw":2,"th":3,"fo":4,"fi":5,"si":6,"se":7,"ei":8,"ni":9}
 for j in a:
  b=j[0:2];c=j[-2:]
  if j[0]=='h':r+=t*100;t=0
  if c=="nd":r=(r+t)*1000;t=0;continue
  if b in d:t+=d[b]
  if c=="ty":t*=10
  if j[-3:]in["een","lve","ten"]:t+=10 
 r+=t
 print r
