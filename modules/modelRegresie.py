# This module is used to generate a data set from a csv file containing the gradings and features of a given number of students homework project
# for the object oriented course
# Using linear regression, the module's purpose is to predict a student's grading based on its features
# The features are : number of classes, number of classes, number of virtual methods classes, class diagrams, readme files, 

#@author Vlad Florea

#We use pandas to manipulate data easier
import pandas as pd

#We use sklearn for splitting the set
from sklearn.model_selection import train_test_split

#We use preprocessing for scalling
from sklearn import preprocessing

import matplotlib.pyplot as plt
import numpy as np

#We will use the sklearn framework to compute the linear regression
from sklearn import linear_model

#sklearn.metrics has a mean_squared_error equivalents for REMS
from sklearn.metrics import mean_squared_error, r2_score 

import sys
sys.path.append("../")

def generateModel(pathToCsv, visual=False):
    print("Generating a linear regression model from "+ pathToCsv)
    #Importing the data set
    projectsTrain= pd.read_csv(pathToCsv)


    #The target is the final grade 
    Y= projectsTrain.Nota

    #The variables are the rest of the features except id
    X= projectsTrain.drop(['Nota'],axis=1)
    X= X.drop(['Id'],axis=1)


    #We split the data set into 2 sets: train and test --> test = 0.2
    test_size_Percentage=0.2
    X_train, X_test,Y_train, Y_test= train_test_split(X,Y,test_size=0.2)

    #Scalling the X_train and X_test data set
    scaler = preprocessing.StandardScaler().fit(X_train)
    X_scaled = scaler.transform(X_train)
    X_train = X_scaled

    scaler = preprocessing.StandardScaler().fit(X_test)
    X_test = scaler.transform(X_test)

    #Definign the regression model
    regrModel = linear_model.LinearRegression()

    #We build our training model
    regrModel.fit(X_train, Y_train)

    #We check it against our test set
    Y_pred = regrModel.predict(X_test)

    #Scale Y_pred between 1- 10
    scaler= preprocessing.MinMaxScaler(feature_range=(1, 10), copy=True, clip=False).fit(Y_pred.reshape(-1,1))
    Y_pred = scaler.transform(Y_pred.reshape(-1,1))


    #Printing informations

    coefIndex =0
    print("The coefficients are:")
    for col in X.columns:
        print(col+"* %.5f"%regrModel.coef_[coefIndex])
        coefIndex+=1

    #print('Coefficients:', regrModel.coef_)
    print('Intercept:',regrModel.intercept_)
    print('RMSE: %.2f'%mean_squared_error(Y_test, Y_pred, squared=False))
    print('Coefficient of determination (R^2):%.2f'%r2_score(Y_test,Y_pred))


    #Plotting the output
    plt.scatter(Y_test, Y_pred, color='black')

    #Plotting the linear regression line
    m,b = np.polyfit(Y_test,Y_pred,1)
    plt.plot(Y_test, m*Y_test+b)


    if(visual == True):
        plt.title("Test data vs Predicted")
        plt.xlabel("ActualVal")
        plt.ylabel("Predicted Val")
        #Adding labels to the plot 
        plt.suptitle('RMSE: %.2f'%mean_squared_error(Y_test, Y_pred, squared=False),)

        plt.xticks(())
        plt.yticks(())
        plt.show()
    return regrModel