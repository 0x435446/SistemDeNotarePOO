class Students:
	def __init__(self):
		self.nr_crt=0
		self.diagrama_clase=False
		self.readme=False
		self.clase=""
		self.headers=[]
		self.classes=[]
		self.virtual_functions=0
		self.numar_clase=0
		self.numar_clase_normale=0
		self.numar_clase_abstracte=0;
		self.numar_interfete=0
		self.numar_mosteniri=0
		self.numar_fisiere=0


	def prints(self):
		self.numar_clase=len(self.classes)
		return self.nr_crt,self.diagrama_clase,self.readme,self.numar_clase,\
		self.numar_clase_normale,self.numar_clase_abstracte,\
		self.numar_interfete,self.numar_mosteniri,self.virtual_functions,self.numar_fisiere

