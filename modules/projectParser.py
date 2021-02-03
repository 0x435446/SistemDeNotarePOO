#This module is used for extracting projects features from a root directory
#@author Cujba Mihai
#@author Nisulescu Alexandru


#We use glob to parse for specific files
import glob

#Importing the rest of the modules
from root import *
from parse import*
from csv_module import *
import os

#We use regex for finding the student id
import re


#This function generates a Student object by lurking in a directory and extracting the student's project features
def extractStudentInfo(folderpath):
    student = Students()
    #Let's search for headers files
    for headerFilename in glob.glob(os.path.join(folderpath, '**/*.h'),recursive=True):
        student.headers.append(headerFilename)
    
    #Searching for virtual functions
    student.virtual_functions=count_virt(student.headers)

    #Searching for inheritances        
    student.numar_mosteniri=count_inh(student.headers)
    
    #Searching for interfaces
    student.numar_interfete,student.numar_clase_abstracte,student.numar_clase_normale=interface_virtuals(student.headers)

    #Counting the lines of code
    student.numar_linii=count_lines(student.headers)

    #Searching for templates
    student.numar_templaturi=count_template(student.headers)
    
    #Let's search for readmes
    for filename in glob.glob(os.path.join(folderpath,'**/*readme*'),recursive=True):
        student.readme=True
    for filename in glob.glob(os.path.join(folderpath,'**/*read me*',),recursive=True):
        student.readme=True
    for filename in glob.glob(os.path.join(folderpath,'**/*read_me*'),recursive=True):
        student.readme=True

    #Let's search for diagrams
    for filename in glob.glob(os.path.join(folderpath,"**/*.jpeg"),recursive=True):
        student.diagrama_clase=True
    for filename in glob.glob(os.path.join(folderpath,"**/*.jpg"),recursive=True):
        student.diagrama_clase=True    
    for filename in glob.glob(os.path.join(folderpath,"**/*.png"),recursive=True):
        student.diagrama_clase=True
    for filename in glob.glob(os.path.join(folderpath,"**/*.svg"),recursive=True):
        student.diagrama_clase=True    

    #Search for .cpp files -->cointains classes
    for cppFile in glob.glob(os.path.join(folderpath,"**/*.cpp"),recursive=True):
        student.classes.append(cppFile)

    #Total number of files
    total = 0
    for root, dirs, files in os.walk(folderpath):
        total += len(files)
    student.numar_fisiere=total
    return student


#This function returns the first level of subdirectories
def getFirstLevelSubdires(d):
    return filter(os.path.isdir, [os.path.join(d,f) for f in os.listdir(d)])



#This function extracts a list of Students objects from a root directory containing student projects
def extractStudentsList(path):
    studList =[]
    subdirs = getFirstLevelSubdires(path)
    for subdir in subdirs:
        regexMatch = re.search(r"student_[0-9]*",subdir)
        if(regexMatch is None):
            #Not a viable entry
            continue
        numberMatch=re.search(r"[0-9][0-9]*",regexMatch.group())
        nrCrt = int(numberMatch.group())

        crtStud=extractStudentInfo(subdir)
        crtStud.nr_crt=nrCrt
        studList.append(crtStud)
    return studList
    
        

