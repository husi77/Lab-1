#include <iostream>
#include <string>
using namespace std;


class Employee {
protected:
    string name;
public:
    Employee(string n) : name(n) {}
    virtual double calculateSalary() = 0;
    virtual void displayInfo() {
        cout << "Employee Name: " << name << endl;
    }
    virtual ~Employee() {}
};


class FullTimeEmployee : public Employee {
private:
    double fixedSalary;
public:
    FullTimeEmployee(string n, double salary) :Employee(n) {

        fixedSalary = salary;

    }
    double calculateSalary() {
        return fixedSalary;
    }
    void displayInfo() {
        Employee::displayInfo();
        cout << "Employment Type: Fulll-Time" << endl;
        cout << "Salary: " << calculateSalary() << endl;
    }
};

class PartTimeEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;
public:
    PartTimeEmployee(string n, double rate, int hours) : Employee(n)
    {

        hourlyRate = rate;
        hoursWorked = hours;
    }
    double calculateSalary() {
        return hourlyRate * hoursWorked;
    }
    void displayInfo() {
        Employee::displayInfo();
        cout << "Employment Type: Part-Time" << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Hourly Rate: " << hourlyRate << endl;
        cout << "Salary: " << calculateSalary() << endl;
    }
};


int main() {
    FullTimeEmployee fte("Hamood", 2300);
    PartTimeEmployee pte("Haibib", 900, 40);

    cout << "===+ Employee Details ===" << endl;
    fte.displayInfo();
    cout << endl;
    pte.displayInfo();

    return 0;
}
