class Vechicle:
    def __init__(self, maxspeed, milleage):
        self.maxspeed = maxspeed
        self.milleage = milleage
        self.total = self.maxspeed * self.milleage
bmw = Vechicle(240, 60)
print(bmw.maxspeed, bmw.milleage)
print(bmw.total)
