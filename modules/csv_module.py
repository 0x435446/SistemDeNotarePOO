import csv
from root import *


def print_NormalCsv(x,csvPath):
	with open(csvPath, mode='w',newline='') as studenti_file:
		studenti_writer = csv.writer(studenti_file, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
		studenti_writer.writerow(['Id','Diagrama de clase','Readme','Numar de clase','Numar clase normale','Numar clase abstracte','Numar interfete','Numar mosteniri','Numar functii virtuale','Numar total de fisiere'])
		for i in range(len(x)):
			studenti_writer.writerow(x[i].prints())

def print_DataSetCsv(x, csvPath):
	with open(csvPath, mode='w',newline='') as studenti_file:
		studenti_writer = csv.writer(studenti_file, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
		studenti_writer.writerow(['Id','Diagrama de clase','Readme','Numar de clase','Numar clase normale','Numar clase abstracte','Numar interfete','Numar mosteniri','Numar functii virtuale','Numar total de fisiere','Nota'])
		for i in range(len(x)):
			studenti_writer.writerow(x[i].prints())
