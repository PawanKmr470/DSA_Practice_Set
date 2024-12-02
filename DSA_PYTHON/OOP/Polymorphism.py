# Base class
class Animal:
    def speak(self):
        # raise NotImplementedError("Subclass must implement abstract method")
        print("Animal Speak!")
        return 

# Derived class 1
class Dog(Animal):
    def speak(self):
        print("Woof!")
        return

# Derived class 2
class Cat(Animal):
    def speak(self):
        print("Meow!")
        return

# Derived class 3
class Cow(Animal):
    def speak(self):
        print("Moo!")
        # super().speak()
        return
    # pass
#

obj = Dog()
obj.speak()

obj = Cat()
obj.speak()

obj = Cow()
obj.speak()