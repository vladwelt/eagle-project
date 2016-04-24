#! /usr/bin/env python

from firebase import firebase 

class FireBase:
	def __init__(self):
		self.firebase=firebase.FirebaseApplication('https://radiant-heat-1615.firebaseio.com/',None)
	def mostrarDatos(self):
		#EXTRAE LOS DATOS DE LA NUBE...
		datos=self.firebase.get('/eagleproject',None)
		for clave, valor in datos.iteritems():
			print "Orientacion: ",valor["orientacion"]
			print "Temperatura: ",valor["temperatura"]
			print "Humedad: ",valor["humedad"]
	def ingresarDatos(self,nuevaOrientacion):
		#Aca se dedidca enviar datos a la BD de un parametro recojido que es la nueva Orientacion
		result = firebase.post('/eagleproject', nuevaOrientacion, {'print': 'pretty'}, {'X_FANCY_HEADER': 'VERY FANCY'})
		result = firebase.post('/eagleproject', nuevaOrientacion, {'print': 'silent'}, {'X_FANCY_HEADER': 'VERY FANCY'})

f=FireBase()
f.mostrarDatos()
f.ingresarDatos(30)
