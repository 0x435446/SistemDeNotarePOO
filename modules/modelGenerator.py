from modelRegresie import *
import pickle

def generate_model():
    modelRegresie = generateModel("./resources/OOPHomeworkTrain.csv",visual=True)
    filename = './resources/grades_model.sav'
    pickle.dump(modelRegresie, open(filename, 'wb'))

def load_model():
    filename = './resources/grades_model.sav'
    return pickle.load(open(filename, 'rb'))