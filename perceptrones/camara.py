import math
import cv2
import os.path
from Perceptron import predict
import numpy as np

def generarImagenesVideo(video):
    video = cv2.VideoCapture(0)
    while True:
        ret,im = video.read()

    cap = cv2.VideoCapture(video)
    i = 1
    triple = []
    titulo=""
    rojo=0
    azul=0
    verde=0


    while True:
        i += 1
        ret, frame = cap.read(-1)
        matriz = (cap.read())
        if i%5 ==0:
            frame = cv2.resize(frame, (600,400))
            grayImage = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
            gaussian = cv2.GaussianBlur(grayImage, (81,81), 0)
            smallImage = cv2.resize(gaussian,(64, 64))
            v = np.array(smallImage)
            vector = np.resize(v,(1,smallImage.size))
            vectorImage = np.concatenate(([[1]], vector), axis=1)
            pred = predict(vectorImage)
            lista = pred.tolist()
            peak = pred.max()
            print peak
            neuron = lista.index(peak) + 1
            #print neuron
            if neuron==1:
                titulo='fuego'
                print titulo
            elif neuron==2:
                titulo = 'agua'
                print titulo
            elif neuron==3:
                titulo = 'edificio'
                print titulo
            elif neuron==4:
                titulo = 'cables'
                print titulo
            elif neuron==5:
                titulo = ''
                print titulo
            font = cv2.FONT_HERSHEY_SIMPLEX
            cv2.putText(frame, titulo ,(19,90), font, 2, (azul,verde,rojo),5)

            cv2.imshow('Prueba de video',im)
            #cv2.imshow("captura", frame)
            #cv2.putText(image,, (x,y), cv2.CV_FONT_HERSHEY_SIMPLEX, 2, 255)
            tecla = cv2.waitKey(10)
            #k = cv2.waitKey(100)
            if k == 27:
                break
                

        cv2.imwrite('captura_img.jpg',im)
            
cv2.destroyAllWindows()

#dir = 'incendio.mp4'
#dir = 'drone.mp4'
#dirDest = 'video/'
#generarImagenesVideo(dir)
