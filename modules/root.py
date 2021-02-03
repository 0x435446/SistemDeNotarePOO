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
		self.numar_clase_abstracte=0
		self.numar_interfete=0
		self.numar_mosteniri=0
		self.numar_fisiere=0
		self.nota= None

	def prints(self):
		self.numar_clase=len(self.classes)
		if(self.nota == None):
			return self.nr_crt,int(self.diagrama_clase),int(self.readme),self.numar_clase,\
			self.numar_clase_normale,self.numar_clase_abstracte,\
			self.numar_interfete,self.numar_mosteniri,self.virtual_functions,self.numar_fisiere
		else:
			return self.nr_crt,int(self.diagrama_clase),int(self.readme),self.numar_clase,\
			self.numar_clase_normale,self.numar_clase_abstracte,\
			self.numar_interfete,self.numar_mosteniri,self.virtual_functions,self.numar_fisiere, self.nota
	