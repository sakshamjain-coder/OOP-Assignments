#include <iostream>
#include <string>
using namespace std;

class Airline
{
    string name, source, destination, departure;
    int age, flightNo;

    static int passengerCount;

public:
    void input()
    {
        cout << "Enter Passenger Name: ";
        getline(cin, name);

        cout << "Enter Passenger Age: ";
        cin >> age;

        cout << "Enter Flight Number: ";
        cin >> flightNo;
        cin.ignore();

        cout << "Enter Departure Time: ";
        getline(cin, departure);

        cout << "Enter Source: ";
        getline(cin, source);

        cout << "Enter Destination: ";
        getline(cin, destination);

        passengerCount++;
    }

    void display()
    {
        cout << "\nPassenger Name: " << name << endl;
        cout << "Passenger Age: " << age << endl;
        cout << "Flight Number: " << flightNo << endl;
        cout << "Departure Time: " << departure << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
    }

    static void showCount()
    {
        cout << "\nTotal Passengers: " << passengerCount << endl;
    }

    friend void showPassenger(Airline a);
};

int Airline::passengerCount = 0;

void showPassenger(Airline a)
{
    cout << "\n--- Passenger Details (Friend Function) ---" << endl;
    cout << "Name: " << a.name << endl;
    cout << "Age: " << a.age << endl;
    cout << "Flight Number: " << a.flightNo << endl;
    cout << "Departure Time: " << a.departure << endl;
    cout << "Source: " << a.source << endl;
    cout << "Destination: " << a.destination << endl;
}

int main()
{
    Airline a1, a2;

    cout << "Enter Details of Passenger 1" << endl;
    a1.input();

    cout << "\nEnter Details of Passenger 2" << endl;
    a2.input();

    cout << "\n--- Passenger 1 Details ---" << endl;
    a1.display();

    cout << "\n--- Passenger 2 Details ---" << endl;
    a2.display();

    Airline::showCount();

    showPassenger(a1);

    return 0;
}