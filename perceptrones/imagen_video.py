import cv2
import numpy as np
#import VisualFilters as vf

cap = cv2.VideoCapture('drone.mp4')
#cap = cv2.VideoCapture(0)
i = 0
while i < 3000:
    ret, frame = cap.read()
    #frame = vf.aumentarIntensidadPorRangoDeColor(frame, 0, 18, 105, 255, 183, 255)
    #frame = cv2.resize(frame, (64, 64))
    print 'agarrando imagen....'+str(i)
    if i % 5 == 0:
        cv2.imwrite('drone' + str(i) + '.png', frame)
    k = cv2.waitKey(10)
    i += 1
    if k == 27:
        break

