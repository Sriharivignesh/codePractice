# https://codefights.com/challenge/SZRtfwnjeBTyk9yy5/main

def helptoclone(A):
    c = j = 0
    for i in A:
        if(i%2==0):
            c+=len(A) - j - 1
            j+=1
    return c

print(helptoclone([9999, 78, 1, 3, 5, 9, 11]))


