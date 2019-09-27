


num0 = 1
num1 = 1
count = 2

while(len(str(num1)) < 1000):
    count += 1
    temp = num1
    num1 = num0 + num1
    num0 = temp



print(count)