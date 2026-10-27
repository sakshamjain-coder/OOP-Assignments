#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class Student {
    int prn;
    char name[50];
    float physics;
    float chemistry;
    float maths;
    float total;
    float percentage;
    char grade;

public:
    void acceptData() {
        cout << "Enter PRN: ";
        cin >> prn;
        cout << "Enter Student Name: ";
        cin.ignore();
        cin.getline(name, 50);

        cout << "Enter Physics Marks: ";
        cin >> physics;
        if (physics < 0) {
            throw string("Error: Physics marks cannot be negative.");
        }

        cout << "Enter Chemistry Marks: ";
        cin >> chemistry;
        if (chemistry < 0) {
            throw string("Error: Chemistry marks cannot be negative.");
        }

        cout << "Enter Maths Marks: ";
        cin >> maths;
        if (maths < 0) {
            throw string("Error: Maths marks cannot be negative.");
        }

        total = physics + chemistry + maths;
        percentage = total / 3.0f;

        if (percentage >= 75) {
            grade = 'A';
        } else if (percentage >= 60) {
            grade = 'B';
        } else if (percentage >= 50) {
            grade = 'C';
        } else if (percentage >= 35) {
            grade = 'D';
        } else {
            grade = 'F';
        }
    }

    void displayData() const {
        cout << setw(10) << prn 
             << setw(20) << name 
             << setw(10) << physics 
             << setw(10) << chemistry 
             << setw(10) << maths 
             << setw(10) << total 
             << setw(10) << percentage 
             << setw(5) << grade << endl;
    }

    int getPrn() const {
        return prn;
    }
};

void addRecord() {
    ofstream outFile("students.dat", ios::binary | ios::app);
    Student s;
    try {
        s.acceptData();
        outFile.write(reinterpret_cast<char*>(&s), sizeof(Student));
        cout << "Record added successfully.\n";
    } catch (string msg) {
        cout << msg << endl;
    }
    outFile.close();
}

void displayAll() {
    ifstream inFile("students.dat", ios::binary);
    if (!inFile) {
        cout << "File could not be opened.\n";
        return;
    }
    Student s;
    cout << setw(10) << "PRN" << setw(20) << "Name" << setw(10) << "Physics" << setw(10) << "Chem" << setw(10) << "Maths" << setw(10) << "Total" << setw(10) << "%" << setw(5) << "Grade" << endl;
    cout << string(85, '-') << endl;
    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        s.displayData();
    }
    inFile.close();
}

void searchRecord(int searchPrn) {
    ifstream inFile("students.dat", ios::binary);
    if (!inFile) {
        cout << "File could not be opened.\n";
        return;
    }
    Student s;
    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        if (s.getPrn() == searchPrn) {
            cout << "Record found:\n";
            cout << setw(10) << "PRN" << setw(20) << "Name" << setw(10) << "Physics" << setw(10) << "Chem" << setw(10) << "Maths" << setw(10) << "Total" << setw(10) << "%" << setw(5) << "Grade" << endl;
            s.displayData();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Record with PRN " << searchPrn << " not found.\n";
    }
    inFile.close();
}

void modifyRecord(int searchPrn) {
    fstream file("students.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "File could not be opened.\n";
        return;
    }
    Student s;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        if (s.getPrn() == searchPrn) {
            cout << "Enter new details for PRN " << searchPrn << ":\n";
            try {
                s.acceptData();
                int pos = -1 * static_cast<int>(sizeof(Student));
                file.seekp(pos, ios::cur);
                file.write(reinterpret_cast<char*>(&s), sizeof(Student));
                cout << "Record updated successfully.\n";
            } catch (string msg) {
                cout << msg << endl;
            }
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Record with PRN " << searchPrn << " not found.\n";
    }
    file.close();
}

void deleteRecord(int searchPrn) {
    ifstream inFile("students.dat", ios::binary);
    if (!inFile) {
        cout << "File could not be opened.\n";
        return;
    }
    ofstream outFile("temp.dat", ios::binary);
    Student s;
    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        if (s.getPrn() == searchPrn) {
            found = true;
        } else {
            outFile.write(reinterpret_cast<char*>(&s), sizeof(Student));
        }
    }
    inFile.close();
    outFile.close();
    remove("students.dat");
    rename("temp.dat", "students.dat");
    if (found) {
        cout << "Record deleted successfully.\n";
    } else {
        cout << "Record with PRN " << searchPrn << " not found.\n";
    }
}

int main() {
    int choice, prn;
    do {
        cout << "\n--- School Marksheet System ---\n";
        cout << "1. Add Student Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Search Record by PRN\n";
        cout << "4. Modify Record\n";
        cout << "5. Delete Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                cout << "Enter PRN to search: ";
                cin >> prn;
                searchRecord(prn);
                break;
            case 4:
                cout << "Enter PRN to modify: ";
                cin >> prn;
                modifyRecord(prn);
                break;
            case 5:
                cout << "Enter PRN to delete: ";
                cin >> prn;
                deleteRecord(prn);
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}