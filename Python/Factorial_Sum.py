# https://codefights.com/challenge/yhN2jyWsWDTWA4qnW/main
import math
def FactorialSum(n):
    a = math.factorial(n)
    p = 0
    while a:
        p+=a %10
        a/=10
    return p

print(FactorialSum(13))



