import serial

class ControlRemoto():
    def __init__(self):
        self.delay = 255
        self.serial_com = serial.Serial(port = '/dev/ttyUSB0',baudrate = 9600)

    def forward(self,vel):
        vel = str(vel)
        delay = str(self.delay)
        cmd = "a"+vel+"t"+delay
        self.serial_com.write(cmd)


    def right(self,vel):
        vel = str(vel)
        delay = str(self.delay)
        cmd = "d"+vel+"t"+delay
        self.serial_com.write(cmd)


    def backward(self,vel):
        vel = str(vel)
        delay = str(self.delay)
        cmd = "r"+vel+"t"+delay
        self.serial_com.write(cmd)


    def left(self,vel):
        vel = str(vel)
        delay = str(self.delay)
        cmd = "i"+vel+"t"+delay
        self.serial_com.write(cmd)



