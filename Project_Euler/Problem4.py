

potNum1 = []
i = 999
k = 999
resetK = k

while i >= 100:
    while k >= 100:
        num = i*k
        numS = str(num)
        if numS[0] == numS[-1]:
            potNum1.append(numS)
        k -= 1
    i-=1
    k = resetK

potNum2 = []
for num in potNum1:
    if str(num)[1] == str(num)[-2]:
        potNum2.append(num)

potNum3 = []
for num in potNum2:
    if str(num)[2] == str(num)[-3]:
        potNum3.append(num)

largest = 0
for num in potNum3:
    if int(num) > largest:
        largest = int(num)

print largest
