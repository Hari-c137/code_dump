def is_prime(n, i=2):
    if n < 2: return 0
    if i * i > n: return 1
    if n%i == 0: return 0
    return is_prime(n, i + 1)

n = int(input("enter a number: "))
print("prime" if is_prime(n) else "not prime")
