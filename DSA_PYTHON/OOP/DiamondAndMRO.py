# Ref : https://www.youtube.com/watch?v=X1PQ7zzltz4
# super() returns a proxy object

# super() searches method up in the chain until it finds the implementation
def super_does_not_call_parent2():
    class Root:
        def fun(self):
            print("Root's fun method")

    class A(Root):
        pass

    class B(A):
        def fun(self):
            print("B's fun method")
            super().fun()

    a = A()
    a.fun()     # Root's fun method

    b = B()
    b.fun()     # B's fun method then Root's fun method

# super_does_not_call_parent2()


# Method Resolution Order
# C -> A -> B -> Root
# In multiple inheritance super() does not necessarily call parent. It can call sibling.
def super_can_access_sibling():
    class Root:
        def fun(self):
            print("Root's fun method")
            return

    class A(Root):
        def fun(self):
            print("A's fun method")
            super().fun()               # super() will call sibling B instead of Root
            return

    class B(Root):
        def fun(self):
            print("B's fun method")
            super().fun()
            return

    class C(A, B):
        def fun(self):
            print("C's fun method")
            super().fun()
            return

    # class D(A, C):                      # Error - here A before C and in C class C before A -> contradiction
    #     def fun(self):
    #         print("D's fun method")
    #         return

    c = C()
    c.fun()

    # d = D()
    # d.fun()

super_can_access_sibling()


