#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Structure to represent a student record
struct Student {
    int rollNo;
    string name;
    string division;
    string address;

    // Function to input student data
    void input() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore(); // To ignore newline character left by cin
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Division: ";
        getline(cin, division);
        cout << "Enter Address: ";
        getline(cin, address);
    }

    // Function to display student data
    void display() const {
        cout << "Roll No: " << rollNo << ", Name: " << name << ", Division: " << division << ", Address: " << address << endl;
    }
};

// Function to add a student record to the file
void addRecord() {
    ofstream outFile("students.dat", ios::app | ios::binary);
    if (!outFile) {
        cerr << "File could not be opened!" << endl;
        return;
    }
    Student student;
    student.input();
    outFile.write(reinterpret_cast<char*>(&student), sizeof(Student));
    cout << "Record added successfully!" << endl;
    outFile.close();
}

// Function to display all student records
void displayRecords() {
    ifstream inFile("students.dat", ios::binary);
    if (!inFile) {
        cerr << "File could not be opened!" << endl;
        return;
    }
    Student student;
    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        student.display();
    }
    inFile.close();
}

// Function to update a student record with a given roll number
void updateRecord() {
    int rollNo;
    cout << "Enter Roll Number to update: ";
    cin >> rollNo;

    fstream file("students.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        cerr << "File could not be opened!" << endl;
        return;
    }

    Student student;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rollNo == rollNo) {
            found = true;
            cout << "Record found. Enter new details:" << endl;
            student.input();  // Get new details from the user
            file.seekp(-static_cast<int>(sizeof(Student)), ios::cur);  // Move the pointer back to the position of the record
            file.write(reinterpret_cast<char*>(&student), sizeof(Student));  // Update the record
            cout << "Record updated successfully!" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Record with Roll No " << rollNo << " not found!" << endl;
    }
    file.close();
}

// Function to add a new student record (a new file operation for clarity)
void addNewRecord() {
    ofstream outFile("students.dat", ios::app | ios::binary);
    if (!outFile) {
        cerr << "File could not be opened!" << endl;
        return;
    }
    Student student;
    student.input();
    outFile.write(reinterpret_cast<char*>(&student), sizeof(Student));
    cout << "New record added successfully!" << endl;
    outFile.close();
}

int main() {
    int choice;
    do {
        cout << "\nStudent Database Menu:\n";
        cout << "1. Add a Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Update a Record\n";
        cout << "4. Add a New Record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                updateRecord();
                break;
            case 4:
                addNewRecord();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
