num = int(input('enter a number:'))

is_prime = num > 1 and all(num % i != 0 for i in range(2,num))
print('prime' if is_prime else 'not prime')
