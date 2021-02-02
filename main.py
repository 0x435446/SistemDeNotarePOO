import sys
sys.path.append('./modules')
from root import *
from parse import *

students=[]
folder="Studenti/"
command="ls "+folder
students = subprocess.check_output(command, shell=True)
students = students.decode().split("\n")
#print (students)
for i in students:
	if len(i)>0:
		command="ls "+folder+i
		files = subprocess.check_output(command, shell=True).decode().split("\n")
		for j in files:
			if(len(j)>0):
				#print ("Fisier:\n",i,"\n",files)
				stud=Students()
				aux=j.lower()
				if "read" in folder+aux:
					stud.readme=True
				if (".png" in folder+aux) or (".jpg" in folder+aux):
					stud.diagrama_clase=True
				command="file "
				#print("COMANDA: ",command3+folder+i+"/"+j)
				#print ("-------------")
				#print (j,len(j))
				#print ("-------------")
				f_type = subprocess.check_output(command+folder+i+"/"+j, shell=True).decode()
				if ("PDF" in f_type) or ("Word" in f_type):
					stud.readme=True
				if ("directory" in f_type) and ("No" not in f_type):
					stud.clase=folder+i+"/"+j
					#print ("DIRECTORY")
				command="ls "
				class_or_h=subprocess.check_output(command+stud.clase, shell=True).decode().split("\n")
				for k in class_or_h:
					if ".h" in k:
						stud.headers.append(k)
					elif ".cpp" in k:
						stud.classes.append(k)
				if len(stud.headers)>0:
					stud.virtual_functions=count_virt(stud.clase,stud.headers)
					stud.numar_mosteniri=count_inh(stud.clase,stud.headers)
					stud.numar_interfete,stud.numar_clase_abstracte,stud.numar_clase_normale=interface_virtuals(stud.clase,stud.headers)