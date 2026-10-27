#include <iostream>
using namespace std;

class Employee
{
public:
    virtual double calculate_salary() = 0;
};

class SalariedEmployee : public Employee
{
    double salary;

public:
    SalariedEmployee(double s)
    {
        salary = s;
    }

    double calculate_salary() override
    {
        return salary;
    }
};

class CommissionEmployee : public Employee
{
    double sales, rate;

public:
    CommissionEmployee(double s, double r)
    {
        sales = s;
        rate = r;
    }

    double calculate_salary() override
    {
        return sales * rate / 100;
    }
};

class HourlyEmployee : public Employee
{
    double hours, wage;

public:
    HourlyEmployee(double h, double w)
    {
        hours = h;
        wage = w;
    }

    double calculate_salary() override
    {
        return hours * wage;
    }
};

int main()
{
    SalariedEmployee e1(30000);
    CommissionEmployee e2(100000, 5);
    HourlyEmployee e3(40, 200);

    Employee *e;

    e = &e1;
    cout << "Salaried Employee Salary: " << e->calculate_salary() << endl;

    e = &e2;
    cout << "Commission Employee Salary: " << e->calculate_salary() << endl;

    e = &e3;
    cout << "Hourly Employee Salary: " << e->calculate_salary() << endl;

    return 0;
}