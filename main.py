import sys
sys.path.append('./modules')
from dataSetFactory import *
from csv_module import *
from modelRegresie import * 
from studentGrader import *
from modelGenerator import *

#Creating the dataset for train
#generateDatasetCsv("./DataSets/train","./DataSets/labels.txt","./resources/OOPHomeworkTrain.csv")

#Creating the csv for testing --> No Grades
#generateNormalCsv("./DataSets/test","./resources/OOPHomeworkTest.csv")

#Generating the regression model
#generate_model()

modelRegresie=load_model()

#Grade students and dump into a csv
gradeACsvOfStudents("./resources/OOPHomeworkTest.csv",modelRegresie, outputCsv="./resources/OOPHomeworkGraded.csv")