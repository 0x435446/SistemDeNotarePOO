import os
import subprocess
def count_virt(path,arr):
	nr=0
	for x in arr:
		if(not os.path.isdir(x)):
			f=open(path+"/"+x, "r")
			text=f.read()
			nr+=text.count("virtual")
	return nr

def count_inh(path, arr):
	nr=0
	for x in arr:
		if(not os.path.isdir(x)):
			try:
				command="cat "+path+"/"+x+" | egrep 'class [A-Za-z_-]* *:'"
				check = subprocess.check_output(command, shell=True)
				if(len(check)>0):
					nr+=1
			except:
				pass
	return nr

def foldersurfer(path):
	arr = os.listdir(path)
	nr=0
	for x in arr:
		if(os.path.isdir(x)):
			nr+=fileCounter(x)
		else:
			nr+=1
	return nr

def fileCounter(path):
	newarr=os.listdir(path)
	nr=0
	for y in newarr:
		if(os.path.isdir(y)):
			nr+=fileCounter(y)
		else:
			nr+=1
	return nr


def interface_virtuals(path,array):
	'''
	string ="#pragma once\
		\
		namespace GameMechanics\
		{\
			class IDamageable\
			{\
			public:\
				virtual void receiveDamage(int) = 0;\
				virtual int getRemainingHP() = 0;\
			};\
		}\
		"
	'''
	interfaces=0
	abstracts=0
	normals=0
	for name in array:
		x = open(path+"/"+name,"r").read().strip().split("\n")
		ok = 0
		da=0
		virtual = 0
		abstract = 0
		f_abstract=0
		interface = 0
		normal=0
		for i in range(len(x)):
			#print ("LINE:",x[i])
			da=0
			if ok == 1:
				if ("{" in x[i]) or ("}" in x[i]) or ("public" in x[i]) or ("private" in x[i]) or ("protected" in x[i]):
					da = 1
				if da == 0:
					if ("virtual" in x[i]):
						virtual = 1
					if virtual == 1:
						if ("0" not in x[i]):
							f_abstract = 1
			if "class" in x[i].lower():
				ok = 1
		#print (name)
		if f_abstract == 1:
			abstract = 1
			abstracts += 1
		elif virtual == 0:
			normal = 1
			normals += 1
		elif virtual == 1 and f_abstract == 0:
			interface = 1
			interfaces += 1
	return interfaces,abstracts,normals