def fib(n):
    A = range(n)
    A[0] = 1;
    A[1] = 1;
    for i in range(2,n):
        A[i] = A[i-2]+A[i-1]
    return A[n-1]

print str(fib(10))
