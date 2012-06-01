class cat:
    def __init__(self, name):
        self.name = name
    def info(self):
        print("im a cat and my name is ", self.name)
    def sound(self):
        print("i make meow sound")
        
class dog:
    def __init__(self, name):
        self.name = name
    def info(self):
        print("im a dawg and my name is ", self.name)
    def sound(self):
        print("i make bark sound")

cat1 = cat("yin")
dog1 = dog("yan")

for animal in (cat1, dog1):
    animal.info()
    animal.sound()
