from threading 
from time 

myFlag = False

# Function to be called when the flag turns on
def myFunction():
    print('Did anyone call me?')

def myTimer():
    global myFlag
    while True:
        if(myFlag):
            myFunction()
            sleep(5)
        else:
            sleep(1)

# Thread that will sleep in background and call your function
# when the myFlag turns to be True
myThread = Thread(target=myTimer)
myThread.start()

myFlag = True