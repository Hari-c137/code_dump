import time

level = int(input("enter the current water level: "))

if (level < 30):
    print("low water level")
    print("turning on water pump")
    while (level != 80):
        level+=1
        print(level)
        time.sleep(0.1)
    print("full water level")
elif (level > 30 and level < 80):
    print("medium water level")
elif (level > 80 and level < 100):
    print("full water level")
