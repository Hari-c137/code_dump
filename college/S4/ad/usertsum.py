num = int(input('enter a number: '))
sum_digit = sum(int(digit) for digit in str(num))
print('sum is', sum_digit)
