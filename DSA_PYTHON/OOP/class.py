
# memberName => Public
# _memberName => Protected
# __memberName => Private

class Employee:
    def getEmpDetails():
        pass

emp1 = Employee()
emp1.getEmpDetails()

# Traceback (most recent call last):
#   File "/Users/PawanKumar.Verma/BootCamp/py_drill/OOP/class.py", line 7, in <module>
#     emp1.getEmpDetails()
# TypeError: getEmpDetails() takes 0 positional arguments but 1 was given

# Python converts "emp1.getEmpDetails()" to
# classname.method(object)
# Employee.getEmpDetails(emp1)
# emp1 is passed hence we require self to refer the object itself.

# Employee.getEmpDetails(emp1) --> emp1.getEmpDetails()


class Employee:
    def employeeDetails(self):
        self.name = "pawan"
        print("Name : ", self.name)
        age = 30
        print("Age : ", age)

    def printEmployeeDetails(self):
        print("In printEmployeeDetails")
        print("Name : ", self.name)
        print("Age : ", age)            # 'age' is not defined error

emp1 = Employee()
emp1.employeeDetails()
emp1.printEmployeeDetails()


# without self variable will be a method local
# with self variable will be a object/instance local
# means we need to make it visible to the other methods of the class also


class Employee:
    def employeeDetails(self):
        self.name = "pawan"
        print("Name : ", self.name)
        self.age = 30
        print("Age : ", self.age)

    def printEmployeeDetails(self):
        print("In printEmployeeDetails")
        print("Name : ", self.name)
        print("Age : ", self.age)

emp1 = Employee()
emp1.employeeDetails()
emp1.printEmployeeDetails()


# Now it will work. But still we have problem that we need to call
# employeeDetails method first because there these variables are initialized
# and in second method they are used.
# Hence we need a mechanism where these instance variables are initialized
# as the object gets created.


class Employee:

    def __init__(self, name, age):
        self.name = name
        self.age = age
        mileage = 10

    def employeeDetails(self):
        self.name = "pawan"
        print("Name : ", self.name)
        self.age = 30
        print("Age : ", self.age)

    def printEmployeeDetails(self):
        print("In printEmployeeDetails")
        print("Name : ", self.name)
        print("Age : ", self.age)

    @staticmethod
    def welcomeMessage():
        print("welcome aboard")

emp1 = Employee("pawan", 34)
emp1.employeeDetails()
emp1.printEmployeeDetails()



class Employee:
    location = "baner"                  # This is class variable not instance variable

    def __init__(self, name, age):
        self.name = name
        self.age = age

    def employeeDetails(self):
        print("Name : ", self.name)
        print("Age : ", self.age)
        print("location : ", self.location)

    def printEmployeeDetails(self):
        print("In printEmployeeDetails")
        print("Name : ", self.name)
        print("Age : ", self.age)
        print("location : ", self.location)

    @staticmethod
    def welcomeMessage():
        print("welcome aboard")


emp1 = Employee("pawan", 34)
emp1.employeeDetails()
emp1.printEmployeeDetails()

emp2 = Employee("john", 32)
emp2.employeeDetails()







