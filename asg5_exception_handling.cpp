#include <iostream>
#include <string>

using namespace std;

class Employee {
    int empId;
    string name;
    int age;
    double income;
    string city;
    string vehicle;

public:
    void acceptData() {
        cout << "Enter Employee ID: ";
        cin >> empId;

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;
        if (age < 18 || age > 55) {
            throw 1;
        }

        cout << "Enter Income: ";
        cin >> income;
        if (income < 50000 || income > 100000) {
            throw 2.5;
        }

        cout << "Enter City: ";
        cin.ignore();
        getline(cin, city);
        if (city != "Pune" && city != "Mumbai" && city != "Bangalore" && city != "Chennai" &&
            city != "pune" && city != "mumbai" && city != "bangalore" && city != "chennai") {
            throw 'c';
        }

        cout << "Enter Vehicle: ";
        getline(cin, vehicle);
        if (vehicle != "4-wheeler" && vehicle != "Car" && vehicle != "car" && vehicle != "Four-wheeler") {
            throw string("vehicle");
        }
    }

    void displayData() {
        cout << "\nEmployee details accepted successfully!" << endl;
        cout << "Employee ID: " << empId << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Income: " << income << endl;
        cout << "City: " << city << endl;
        cout << "Vehicle: " << vehicle << endl;
    }
};

int main() {
    Employee emp;

    try {
        emp.acceptData();
        emp.displayData();
    }
    catch (int) {
        cout << "Exception Caught: Age must be between 18 and 55." << endl;
    }
    catch (double) {
        cout << "Exception Caught: Income must be between Rs. 50,000 and Rs. 1,00,000." << endl;
    }
    catch (char) {
        cout << "Exception Caught: City must be Pune, Mumbai, Bangalore, or Chennai." << endl;
    }
    catch (string) {
        cout << "Exception Caught: Employee must have a 4-wheeler." << endl;
    }

    return 0;
}