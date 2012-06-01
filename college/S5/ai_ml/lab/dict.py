hm = { "Name":"Harry", "Address":"NYC, "no":133769420 }

# print(hm)
# print(len(hm))
print(hm)
print()
print(hm.keys())
print(hm.values())

del(hm["no"]) # deletes entire entry
print(hm.items())

addr = hm.pop("Address") # similar to del() but the it returns the popped value
print(addr)
print(hm.items())
print(hm)
hm.update({"Designation":"SysAdmin"})
print(hm)


"""
dictionary = {"key":"value", "anotherKey":"anotherValue"}
del(dictionary["key"])
returnedValue = dictionary.pop()
dictionary.items()
dictionary.values()
dictionary.keys()
dictionary.update({"newKey":"newValue"})


"""
