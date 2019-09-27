


def FibbSumEven(term):
      a = 1
      b = 2
      sumF = 0
      while (a and b) < term:
            if (a%2)==0:
                  sumF += a
                  print "a is: " + str(a)
            if (b%2)==0:
                  sumF += b
                  print "b is: " + str(b)
            a = b + a
            b = a + b
      print "Result is: " + str(sumF)


FibbSumEven(int(raw_input("Term: ")))
