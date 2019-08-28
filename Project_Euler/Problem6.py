squareOfSum = 0
sumOfSquares = 0
for i in range(1,101):
    squareOfSum += i
    sumOfSquares += pow(i,2)
    

squareOfSum = pow(squareOfSum,2)

print squareOfSum - sumOfSquares
