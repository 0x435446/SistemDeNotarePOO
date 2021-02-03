#This module will generate csv datasets from a root directory and a labels file
#@author Vlad Florea
from projectParser import *
import re

#Generate a csv without the grading column
def generateNormalCsv(rootDir,outPutCsv):
    studenti = extractStudentsList(rootDir)
    print_NormalCsv(studenti,outPutCsv)


#Generate a csv with the grading column   
def generateDatasetCsv(rootDir, labelsPath, outputCsv):
    studenti = extractStudentsList(rootDir)
    tempList = list.copy(studenti)
    # Opening file
 
    #Search for every student in the label file
    for student in studenti:
        labelFile = open(labelsPath, 'r')
        for line in labelFile:
            columns = line.strip().split("\t\t")
            if(len(columns) != 2):
                print("Wrong labels format!!")
                return
               
            regexMatch = re.search(r"student_[0-9]*",columns[0])
            if(regexMatch is None):
                #Not a viable entry
                continue
            numberMatch=re.search(r"[0-9][0-9]*",regexMatch.group())
            if(student.nr_crt == int(numberMatch.group())):
                if(columns[1] == "NaN"):
                    #If its not a number, the the grade is 1 -> Minimum
                    columns[1]=1
                student.nota = float(columns[1])
                #We found a match--> we can brake
                break
        if student.nota is None:
            #Remove the current student from the list --> he has no grade
            print("Found no grade for student with id:"+str(student.nr_crt)+" -> removing him!")
            tempList.remove(student)
            # Closing file
        labelFile.close()
    studenti = list.copy(tempList)
    
    print_DataSetCsv(studenti,outputCsv)