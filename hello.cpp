#include <iostream>
using namespace std;

// Static Data Member
class Counter {
public:
    static int count;

    Counter() {
        count++;
    }
};

int Counter::count = 0;

// Abstract Class
class Person {
protected:
    string name;

public:
    Person(string n) {
        name = n;
    }

    virtual void display() = 0; // Pure Virtual Function
};

// Base Class
class Student : public Person {
protected:
    int rollNo;

public:
    Student(string n, int r) : Person(n) {
        rollNo = r;
    }

    void display() override {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
    }
};

// Multilevel Inheritance
class Result : public Student {
private:
    int marks;

public:
    Result(string n, int r, int m) : Student(n, r) {
        marks = m;
    }

    void display() override {
        Student::display();
        cout << "Marks: " << marks << endl;
    }

    // Friend Function
    friend void showMarks(Result r);
};

void showMarks(Result r) {
    cout << "Friend Function Accessing Marks: "
         << r.marks << endl;
}

// Operator Overloading
class Complex {
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    Complex operator+(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

// Destructor Example
class Demo {
public:
    Demo() {
        cout << "Constructor Called" << endl;
    }

    ~Demo() {
        cout << "Destructor Called" << endl;
    }
};

int main() {

    // Static Member Demo
    Counter c1, c2, c3;
    cout << "Objects Created: "
         << Counter::count << endl;

    // Constructor & Destructor Demo
    Demo d;

    // Inheritance & Polymorphism
    Result r("Akshi", 101, 95);

    cout << "\nStudent Details:" << endl;
    r.display();

    showMarks(r);

    // Operator Overloading
    Complex cA(4, 5), cB(2, 3);
    Complex cC = cA + cB;

    cout << "\nComplex Number Addition:" << endl;
    cC.display();

    return 0;
}
