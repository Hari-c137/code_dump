list = []
i = 1
while i <= 7:
    a = float(input("Please enter " + str(i) +  " list : "))
    list.append(a)
    i+=1
print(list)
avg = sum(list) / len(list)
print(avg)
