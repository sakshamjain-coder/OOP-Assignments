#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    string Emp_name, Address, Mail_id;
    int Emp_id;
    long long Mobile_no;

public:
    void inputDetails()
    {
        cout << "Enter Employee ID: ";
        cin >> Emp_id;
        cin.ignore();

        cout << "Enter Employee Name: ";
        getline(cin, Emp_name);

        cout << "Enter Address: ";
        getline(cin, Address);

        cout << "Enter Mail ID: ";
        getline(cin, Mail_id);

        cout << "Enter Mobile Number: ";
        cin >> Mobile_no;
    }

    void displayPaySlip(string designation, double basicPay)
    {
        double DA = basicPay * 0.97;
        double HRA = basicPay * 0.10;
        double PF = basicPay * 0.12;
        double clubFund = basicPay * 0.001;

        double grossSalary = basicPay + DA + HRA;
        double netSalary = grossSalary - PF - clubFund;

        cout << "\n----- Employee Pay Slip -----" << endl;
        cout << "Designation: " << designation << endl;
        cout << "Employee ID: " << Emp_id << endl;
        cout << "Name: " << Emp_name << endl;
        cout << "Address: " << Address << endl;
        cout << "Mail ID: " << Mail_id << endl;
        cout << "Mobile Number: " << Mobile_no << endl;
        cout << "Basic Pay: " << basicPay << endl;
        cout << "DA: " << DA << endl;
        cout << "HRA: " << HRA << endl;
        cout << "Gross Salary: " << grossSalary << endl;
        cout << "PF: " << PF << endl;
        cout << "Staff Club Fund: " << clubFund << endl;
        cout << "Net Salary: " << netSalary << endl;
    }

    virtual void generatePaySlip() = 0;
};

class Programmer : public Employee
{
    double basicPay;

public:
    void generatePaySlip() override
    {
        cout << "\nEnter Programmer Details" << endl;
        inputDetails();
        cout << "Enter Basic Pay: ";
        cin >> basicPay;
        displayPaySlip("Programmer", basicPay);
    }
};

class TeamLead : public Employee
{
    double basicPay;

public:
    void generatePaySlip() override
    {
        cout << "\nEnter Team Lead Details" << endl;
        inputDetails();
        cout << "Enter Basic Pay: ";
        cin >> basicPay;
        displayPaySlip("Team Lead", basicPay);
    }
};

class AssistantProjectManager : public Employee
{
    double basicPay;

public:
    void generatePaySlip() override
    {
        cout << "\nEnter Assistant Project Manager Details" << endl;
        inputDetails();
        cout << "Enter Basic Pay: ";
        cin >> basicPay;
        displayPaySlip("Assistant Project Manager", basicPay);
    }
};

class ProjectManager : public Employee
{
    double basicPay;

public:
    void generatePaySlip() override
    {
        cout << "\nEnter Project Manager Details" << endl;
        inputDetails();
        cout << "Enter Basic Pay: ";
        cin >> basicPay;
        displayPaySlip("Project Manager", basicPay);
    }
};

int main()
{
    Programmer p;
    TeamLead t;
    AssistantProjectManager a;
    ProjectManager m;

    Employee *e;

    e = &p;
    e->generatePaySlip();

    e = &t;
    e->generatePaySlip();

    e = &a;
    e->generatePaySlip();

    e = &m;
    e->generatePaySlip();

    return 0;
}