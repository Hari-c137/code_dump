class emp:
    def input(self):
        self.name = input("enter name: ")
        self.dsgn = input("enter designation: ")
        self.basic = int(input("enter basic salary: "))
    def compute(self):
        self.da = self.basic * (30 / 100)
        self.hra = self.basic * (4 / 100)
        self.gros = self.basic + self.da + self.hra
        self.pf = self.basic * (5 / 100)
        self.insurance=500
        self.ded = self.pf + self.insurance
        self.net = self.gros - self.ded
    def print(self):
        print("Empolyee Details")
        print("Name: ", self.name)
        print("Designation: ", self.dsgn)
        print("Total Salary: ", self.gros)
        print("Net Salary: ", self.net)

dp1 = emp()

dp1.input()
dp1.compute()
dp1.print()
