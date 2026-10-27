#include <iostream>
#include <string>
using namespace std;

class Employee
{
    string name, qualification, address;
    int id;
    long long contact;
    double basic, DA, TA, HRA, netSalary;

public:
    // Default constructor
    Employee()
    {
        name = "Not Assigned";
        qualification = "Not Assigned";
        address = "Not Assigned";
        id = 0;
        contact = 0;
        basic = 0;
        DA = TA = HRA = netSalary = 0;
        cout << "Default Constructor Called" << endl;
    }

    // Parameterized constructor
    Employee(string n, int i, string q, string a,
             long long c, double b)
    {
        name = n;
        id = i;
        qualification = q;
        address = a;
        contact = c;
        basic = b;

        DA = basic * 0.97;
        TA = basic * 0.10;
        HRA = basic * 0.10;
        netSalary = basic + DA + TA + HRA;

        cout << "Parameterized Constructor Called" << endl;
    }

    // Copy constructor
    Employee(const Employee &e)
    {
        name = e.name;
        id = e.id;
        qualification = e.qualification;
        address = e.address;
        contact = e.contact;
        basic = e.basic;
        DA = e.DA;
        TA = e.TA;
        HRA = e.HRA;
        netSalary = e.netSalary;

        cout << "Copy Constructor Called" << endl;
    }

    // Display employee information
    void display()
    {
        cout << "\nEmployee Name: " << name << endl;
        cout << "Employee ID: " << id << endl;
        cout << "Qualification: " << qualification << endl;
        cout << "Address: " << address << endl;
        cout << "Contact Number: " << contact << endl;
        cout << "Basic Salary: " << basic << endl;
        cout << "DA: " << DA << endl;
        cout << "TA: " << TA << endl;
        cout << "HRA: " << HRA << endl;
        cout << "Net Salary: " << netSalary << endl;
    }

    // Destructor
    ~Employee()
    {
        cout << "Destructor Called for Employee ID: "
             << id << endl;
    }
};

int main()
{
    // Default constructor
    Employee e1;
    e1.display();

    // Parameterized constructor using dynamic allocation
    Employee *e2 = new Employee(
        "Rahul", 101, "B.Tech", "Pune",
        9876543210LL, 30000
    );

    e2->display();

    // Copy constructor
    Employee e3(*e2);
    e3.display();

    // Array of objects
    cout << "\nEmployee Array:" << endl;
    Employee employees[2];

    employees[0] = Employee(
        "Priya", 102, "M.Tech", "Mumbai",
        9876543211LL, 40000
    );

    employees[1] = Employee(
        "Amit", 103, "BCA", "Delhi",
        9876543212LL, 25000
    );

    employees[0].display();
    employees[1].display();

    // Free dynamically allocated memory
    delete e2;

    return 0;
}