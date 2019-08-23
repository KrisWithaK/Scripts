

totalLetters = 0

for num in range(1, 1001, 1):
    letters = 0
    thisNum = num

    if(len(str(thisNum)) == 4):
        letters += 11 # one thousand edge case

    if(len(str(thisNum)) == 3):
        if(str(thisNum) == str(100) or str(thisNum) == str(200) or str(thisNum) == str(600)):
            letters += 10
        elif(str(thisNum) == str(400) or str(thisNum) == str(500) or str(thisNum) == str(900)):
            letters += 11
        elif(str(thisNum) == str(300) or str(thisNum) == str(700) or str(thisNum) == str(800)):
            letters += 12
        elif(str(thisNum)[0] == str(1) or str(thisNum)[0] == str(2) or str(thisNum)[0] == str(6)):
            letters += 13
        elif(str(thisNum)[0] == str(4) or str(thisNum)[0] == str(5) or str(thisNum)[0] == str(9)):
            letters += 14
        elif(str(thisNum)[0] == str(3) or str(thisNum)[0] == str(7) or str(thisNum)[0] == str(8)):
            letters += 15 

        thisNum = str(thisNum)[1:]

    if(len(str(thisNum)) == 2):
        if(str(thisNum)[0] == str(1)):
            if(str(thisNum) == str(10)):
                letters += 3 
            if(str(thisNum) == str(11) or str(thisNum) == str(12)):
                letters += 6
            elif(str(thisNum) == str(15) or str(thisNum) == str(16)):
                letters += 7
            elif(str(thisNum) == str(13) or str(thisNum) == str(14) or str(thisNum) == str(18) or str(thisNum) == str(19)):
                letters += 8
            elif(str(thisNum) == str(17)):
                letters += 9
        elif(str(thisNum)[0] == str(2) or str(thisNum)[0] == str(3) or str(thisNum)[0] == str(8) or str(thisNum)[0] == str(9)):
            letters += 6 
        elif(str(thisNum)[0] == str(5) or str(thisNum)[0] == str(6) or str(thisNum)[0] == str(4)):
            letters += 5

        elif(str(thisNum)[0] == str(7)):
            letters += 7 

        if(str(thisNum)[0] != str(1)):
            thisNum = str(thisNum)[1:]

    if(len(str(thisNum)) == 1):
        if(str(thisNum)[0] == str(1) or str(thisNum)[0] == str(2) or str(thisNum)[0] == str(6)):
            letters += 3 
        elif(str(thisNum)[0] == str(4) or str(thisNum)[0] == str(5) or str(thisNum)[0] == str(9)):
            letters += 4
        elif(str(thisNum)[0] == str(3) or str(thisNum)[0] == str(7) or str(thisNum)[0] == str(8)): 
            letters += 5

    totalLetters += letters
    #print(str(num) + " " + str(letters))

print(totalLetters) 


