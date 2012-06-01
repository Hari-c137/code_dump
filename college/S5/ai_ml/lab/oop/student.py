class student:
    def details(self):
        self.rollno = int(input("enter the roll no: "))
        self.name   = input("enter name: ")
        self.m = int(input("enter maths marks:"))
        self.p = int(input("enter physics marks:"))
        self.c = int(input("enter chemistry marks:"))
    def result(self):
        self.tot = self.m + self.p + self.c
        self.per = self.tot / 300 * 100
        print(self.rollno, self.name, self.tot, self.per)

S5 = student()
S5.details()
S5.result()
