


def largestPrime(num):
    i = 1
    while i <= num:
        if num % i == 0:
            num = num/i
        i += 1
    print i-1
        


largestPrime(int(raw_input("enter a number: ")))
