# APAC Sept
import sys
import copy
n = int(sys.stdin.readline())

def findV(map,map2):
	for key in map:
		if(valueRet(map,map2,key,[key])):
			map2[key]=1

	#print map2
	for key in map:
		if not map2.get(key):
			return 0

	return 1

def valueRet(map,map2,str,li):
	ll=map.get(str)
	if(not ll):
		map2[str]=0
		return 0
	elif(len(ll)==1 and ll[0]==''):
		map2[str]=1
		return 1
	else:
		for s1 in ll:
			ll1=copy.copy(li)
			ll1.append(s1)
			if(s1 in li or valueRet(map,map2,s1,ll1)==0):
				map2[str]=0
				return 0

		map2[str]=1
		return 1


for i in range(0,n):
	map = dict()
	map2 = dict()
	k = int(sys.stdin.readline())

	for j in range(0,k):
		str1 = sys.stdin.readline()
		str1 = str1.split('=')
		key=str1[0]
		valstr = ((str1[1].split('('))[1].split(')'))[0]
		val = valstr.split(',')
		
		map[key]=list(set(val))

	if(findV(map,map2)==0):
		print("Case #"+str(i+1)+": BAD")
	else:
		print("Case #"+str(i+1)+": GOOD")