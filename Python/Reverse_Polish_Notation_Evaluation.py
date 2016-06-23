#https://codefights.com/challenge/qsRziH273jPy4p4ga/main

def RPN(e):
    n = 0
    r = []
    k = 0
    a = 0
    b = 0
    for i in range(len(e)):
        if(e[i].isspace()):
            if(k == 1):
                r.append(n)
            n = 0
        elif(e[i] == '+'):
            b = r.pop()
            a = r.pop()
            r.append(a + b)
            k = 0
        elif(e[i] == '-'):
            b = r.pop()
            a = r.pop()
            r.append(a - b)
            k = 0
        elif(e[i] == '*'):
            b = r.pop()
            a = r.pop()
            r.append(a * b)
            k = 0
        elif(e[i] == '/'):
            b = r.pop()
            a = r.pop()
            r.append(a / b)
            k = 0
        elif(e[i] == '%'):
            b = r.pop()
            a = r.pop()
            r.append(a % b)
            k = 0
        elif(e[i] == '^'):
            b = r.pop()
            a = r.pop()
            r.append(a**b)
            k = 0
        else:
            n = n*10;
            n = n + (int)(e[i])
            k = 1

    return r.pop()

print(RPN("4 0 3 - -"))



