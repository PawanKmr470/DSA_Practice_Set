#include <iostream>
using namespace std;

// OCP - A software artifact should be open for extension but closed for modification.

class Shape {
public:
    virtual double calculateArea() const = 0;
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double width, double height) : width(width), height(height) {}

    double calculateArea() const override {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double radius) : radius(radius) {}

    double calculateArea() const override {
        return M_PI * radius * radius;
    }
};

// Usage
void printArea(const Shape& shape) {
    cout << "Area: " << shape.calculateArea() << endl;
}

//#######################################################

// Before applying OCP
class Account {
  private:
    double balance;
    int type_of_account;
  public:
    Account(double balance, int type_of_account) : balance(balance), type_of_account(type_of_account) {}

    void deposit(double amount) {
      balance += amount;
    }
  
    void withdraw(double amount) {
      balance -= amount;
    }

    double getBalance() const {
      return balance;
    }

    double calculateInterest() const {
      if (type_of_account == 1) {

      } else if (type_of_account == 2) {

      } .....
      // LOGIC based on type of account
    }
}; 

// After applying OCP
class Account {
    public:
        virtual void deposit(double balance) = 0;
        virtual void withdraw(double balance) = 0;
        virtual double getBalance() = 0;
        virtual double calculateInterest() = 0;
}; 

class SavingsAccount : public Account {
    private:
        double balance; 
    public :
        SavingsAccount(double balance) : balance(balance) {}
        
        void deposit(double amount) override {
            balance += amount;
        }
        
        void withdraw(double amount) override {
            balance -= amount;
        }
        
        double getBalance() override {
            return balance;
        }
        
        double calculateInterest() override {
            return balance * 0.04; // 4% interest rate 
        }
};

class FixedDepositAccount : public Account {
    private:
        double balance; 
        int time;
    public :
        FixedDepositAccount(double balance, int time) : balance(balance) {}
        
        void deposit(double amount) override {
            balance += amount;
        }
        
        void withdraw(double amount) override {
            // Logic to withdraw after certain time
            balance -= amount;
        }
        
        double getBalance() override {
            return balance;
        }
        
        double calculateInterest() override {
            return balance * 0.08; // 8% interest rate 
        }
}; 

class CreditCardAccount : public Account {
    private:
        double balance;
        double limit;
    public:
        CreditCardAccount(double balance, double limit) : balance(balance), limit(limit) {}
        void deposit(double amount) override {
            balance -= amount;
        }
        void withdraw(double amount) override {
            balance += amount; // credit card withdrawal
        }
        double getBalance() override {
            return balance;
        }
        double calculateInterest() override {
            return balance * 0.18; // 18% interest rate
        }

        void increaseLimit(double addon) {
            limit += addon;
        }
};

//#######################################################

// Before applying OCP

class PaymentProcessor {
    public:
    void processPayment(Payment* payment) {
        if (payment->type() == "CreditCard") {
        // Process credit card payment.
        } else if (payment->type() == "PayPal") {
        // Process PayPal payment.
        } else {
        // Unknown payment type.
        }
    }
};


// After applying OCP

class Payment {
    public:
    virtual ~Payment() {}
    virtual void process() = 0;
};

class CreditCardPayment : public Payment {
    public:
    void process() override {
        // Process credit card payment.
    }
};

class PayPalPayment : public Payment {
    public:
    void process() override {
        // Process PayPal payment.
    }
};

class BitcoinPayment : public Payment {
    public:
    void process() override {
        // Process Bitcoin payment.
    }
};

class PaymentProcessor {
    public:
    void processPayment(Payment* payment) {
        payment->process();
    }
};