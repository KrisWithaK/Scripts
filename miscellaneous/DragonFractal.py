import matplotlib.pyplot as plt
import time

def dragon_fractal(n):              #returns a graph of the dragon fractal of n iterations
  pointlist = [[0,0],[0,1]]         #contains list of xy coordinates and the initial points
  rotationaxis = [0,1]              #initial rotation axis
  
  if n ==0:
    pass
  else:
    for iterations in range(n):
      Templist = []                 #to be fused with pointlist after collecting point images   
      for point in pointlist:
        pointimage = [rotationaxis[0] + rotationaxis[1] - point[1], rotationaxis[1] - rotationaxis[0] + point[0]]
        if pointimage == point:
          continue
        else:
          Templist.append(pointimage)
      Templist.reverse()
      pointlist = pointlist + Templist
      rotationaxis = [rotationaxis[0] + rotationaxis[1], rotationaxis[1] - rotationaxis[0]]

  xlist = []
  ylist = []
  for point in pointlist:
    xlist.append(point[0])
    ylist.append(point[1])
  print(pointlist)
  plt.plot(xlist,ylist, ".r-")
  plt.show()
  #plt.savefig("Dragon Fractal")


for i in range(0, 2):
  dragon_fractal(i)
  time.sleep(2)