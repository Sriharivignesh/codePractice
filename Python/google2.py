def answer(total_lambs):
    # your code here
        fib_reference = [1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733]
        squares_reference = [1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912]
        stingy = 0
        generous = 0
        tsum = 0
        for i in fib_reference:
            if(tsum > total_lambs):
                break
            tsum += i
            stingy += 1

        tsum = 0
        for i in squares_reference:
            if(tsum > total_lambs):
                break
            tsum += i
            generous += 1
            
        return (stingy - generous)


print(answer(143))