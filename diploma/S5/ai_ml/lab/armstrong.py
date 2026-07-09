def armstrong_sum(n):
    p = len(str(n))
    def helper(x):
        return 0 if x == 0 else (x % 10) ** p + helper(x // 10)
    return helper(n)

n = int(input("Enter a number: "))
print(f"{n} is an Armstrong number" if n == armstrong_sum(n) else f"{n} is not an Armstrong number")
