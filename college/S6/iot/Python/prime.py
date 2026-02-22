import time
import math

for num in range(2, 10):
    if all(num%i != 0 for i in range(2, int(math.sqrt(num))+1)):
        print (num)
        time.sleep(1)
