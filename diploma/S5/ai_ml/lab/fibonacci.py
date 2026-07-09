def fibo(n):
    if n < 2:
        return n
    return fibo(n-1) + fibo(n-2)

n = int(input("Enter an integer: "))

for i in range(n + 1):
    print(fibo(i), end=" ")
