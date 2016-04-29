"""
Avanza, los dos motores marchan en el mismo sentido 
Gp 11: 1 |  Gp 16: 1   
Gp 15: 0 |  Gp 18: 0
"""
import RPi.GPIO as GPIO
import time

class ControlRemot():
	def __init__(self):
		GPIO.setmode(GPIO.BOARD)
		GPIO.setup(11,GPIO.OUT)#Motor1
                GPIO.setup(15,GPIO.OUT)
		GPIO.setup(16,GPIO.OUT)#motor2
		GPIO.setup(18,GPIO.OUT)
		self.parar()
	def avanzar(self):
		GPIO.output(11,False)
		GPIO.output(15,True)
		GPIO.output(16,True)
		GPIO.output(18,False)
        def parar(self):
		GPIO.output(11,True)
		GPIO.output(15,True)

		GPIO.output(16,True)
		GPIO.output(18,True)
	def izquierda(self):
		GPIO.output(11,True)
		GPIO.output(15,True)

		GPIO.output(16,True)
		GPIO.output(18,False)
	def derecha(self):
		GPIO.output(11,False)
		GPIO.output(15,True)

		GPIO.output(16,True)
		GPIO.output(18,True)	
	def atras(self):
		GPIO.output(11,True)
		GPIO.output(15,False)

		GPIO.output(16,False)
		GPIO.output(18,True)
	def autonomo(self):
		"""
		controler = ControlRemot()
		controler.avanzar()
		"""
		self.avanzar()
		time.sleep(5)
		#controler.parar()
		self.parar()
		time.sleep(1)
		self.derecha()
		time.sleep(5)
		self.parar()
		time.sleep(1)
		self.derecha()
		time.sleep(5)
		self.parar()
		time.sleep(1)
		self.izquierda()
		time.sleep(5)
		self.parar()
		time.sleep(1)
		self.izquierda()
		time.sleep(5)
		self.parar()
		time.sleep(1)
		self.izquierda()
		time.sleep(5)
		self.parar()


control_remoto = ControlRemot()
control_remoto.autonomo()
#time.sleep(5)
#control_remoto.parar()
#time.sleep(5)
#control_remoto.atras()
