import sys
sys.path.append('./modules')
from dataSetFactory import *
from csv_module import *
from modelRegresie import * 
from studentGrader import *


#Creating the dataset for train
#generateDatasetCsv("./DataSets/train","./DataSets/labels.txt","./resources/OOPHomeworkTrain.csv")

#Creating the csv for testing --> No labels
#generateNormalCsv("./DataSets/test","./resources/OOPHomeworkTest.csv")


modelRegresie = generateModel("./resources/OOPHomeworkTrain.csv")

gradeACsvOfStudents("./resources/OOPHomeworkTest.csv",modelRegresie, outputCsv="./resources/OOPHomeworkGraded.csv")