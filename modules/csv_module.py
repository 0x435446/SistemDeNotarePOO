import csv
from root import *


def print_csv(x):
	with open('studenti.csv', mode='w') as studenti_file:
		studenti_writer = csv.writer(studenti_file, delimiter='\t', quotechar='"', quoting=csv.QUOTE_MINIMAL)
		studenti_writer.writerow(['Nr.crt','Diagrama de clase','Readme','Numar de clase','Numar clase normale','Numar clase abstracte','Numar interfete','Numar mosteniri','Numar functii virtuale','Numar total de fisiere'])
		for i in range(len(x)):
			studenti_writer.writerow(x[i].prints())
