#This module's purpose is to implement the functions necessary for grading a student
#@author Vlad Florea

#self.nr_crt=0
from modelRegresie import*
from root import *
def gradeAStudent(stud: Students, modelRegresie):
    X = []
    X.append(int(stud.diagrama_clase))
    X.append(int(stud.readme))
    X.append(stud.numar_clase)
    X.append(stud.numar_clase_normale)
    X.append(stud.numar_clase_abstracte)
    X.append(stud.numar_interfete)
    X.append(stud.numar_mosteniri)
    X.append(stud.virtual_functions)
    X.append(stud.numar_fisiere)

    #Scalling 
    scaler = preprocessing.StandardScaler().fit(X)
    X_scaled = scaler.transform(X)

    #Predicting the grade
    gradePredicted = modelRegresie.predict(X_scaled)

    return gradePredicted


def gradeACsvOfStudents(csvPath, modelRegresie, outputCsv= None):
    print("Grading students from "+csvPath)

    #Importing the data set
    X_origin= pd.read_csv(csvPath)

    #The variables are all the columns except the id
    X= X_origin.drop(['Id'],axis=1)

    #Scalling 
    scaler = preprocessing.StandardScaler().fit(X)
    X_scaled = scaler.transform(X)

    Y_pred = modelRegresie.predict(X_scaled)

    #Adding new column
    X_origin["Nota"] = Y_pred

    print("Final grades are:")
    #The marks are 
    print(X_origin)

    if(outputCsv !=None):
        X_origin.to_csv(outputCsv, index= False)



