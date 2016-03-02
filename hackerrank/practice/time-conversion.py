time = raw_input()
flag = time[-2:]
if flag == "PM":
	if time[:2] != "12":
		hour = str(int(time[:2])+12)
	else: hour = "12"
	#print "Hour1: " , hour
if flag == "AM":
	if time[:2] == "12":
		hour = "00"
	else:
		hour = time[:2]
	#print "Hour2: " , hour
print hour + time[2:8]