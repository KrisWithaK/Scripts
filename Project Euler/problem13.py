

numbersFile = open("numbers", "r")
sum = 0

for line in numbersFile:
    sum += int(line)

print(sum)
numbersFile.close()