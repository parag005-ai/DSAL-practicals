#include <iostream>
#include <fstream>
using namespace std;

class student {
public:
    int roll;
    char name[50];
    char div;
    char address[50];

    void get();
    void show();
    void add();
    void search();
    void append();
    void del();
    void display();
};

void student::get() {
    cout << "Enter roll number of student: ";
    cin >> roll;
    cin.ignore();

    cout << "Enter name of student: ";
    cin.getline(name, 50);

    cout << "Enter division of the student: ";
    cin >> div;
    cin.ignore();

    cout << "Enter address of the student: ";
    cin.getline(address, 50);
}

void student::show() {
    cout << "\n-----------------------------\n";
    cout << "Name of the student     : " << name << endl;
    cout << "Roll number of student  : " << roll << endl;
    cout << "Division of the student : " << div << endl;
    cout << "Address of the student  : " << address << endl;
    cout << "-----------------------------\n";
}

void student::add() {
    student s;
    ofstream f("parag.txt", ios::out | ios::binary | ios::app);
    s.get();
    f.write((char *)&s, sizeof(s));
    f.close();
    cout << "Student record added successfully.\n";
}

void student::search() {
    student s;
    ifstream f("parag.txt", ios::in | ios::binary);
    int r, fc = 0;

    cout << "Enter the roll number to search: ";
    cin >> r;

    while (f.read((char *)&s, sizeof(s))) {
        if (s.roll == r) {
            cout << "Student record is found:\n";
            s.show();
            fc = 1;
            break;
        }
    }

    f.close();

    if (fc == 0) {
        cout << "Student record not found.\n";
    }
}

void student::append() {
    student s;
    ofstream f("parag.txt", ios::out | ios::binary | ios::app);
    int n;

    cout << "Enter the number of students to add: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter information for student " << i + 1 << ":\n";
        s.get();
        f.write((char *)&s, sizeof(s));
    }
    f.close();
    cout << "\nStudent information added successfully.\n";
}

void student::del() {
    student s;
    ifstream f1("parag.txt", ios::in | ios::binary);
    ofstream f2("pc.txt", ios::out | ios::binary);

    int rr, found = 0;
    cout << "Enter the roll number to delete: ";
    cin >> rr;

    while (f1.read((char *)&s, sizeof(s))) {
        if (s.roll == rr) {
            cout << "Student record deleted successfully.\n";
            found = 1;
        } else {
            f2.write((char *)&s, sizeof(s));
        }
    }

    f1.close();
    f2.close();

    if (found == 0) {
        cout << "Sorry, student record not found.\n";
    } else {
        remove("parag.txt");
        rename("pc.txt", "parag.txt");
    }
}

void student::display() {
    student s;
    ifstream f("parag.txt", ios::in | ios::binary);

    cout << "\nDisplaying all student records:\n";
    while (f.read((char *)&s, sizeof(s))) {
        s.show();
    }

    f.close();
}

int main() {
    student s;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Append Students\n";
        cout << "4. Delete Student\n";
        cout << "5. Display All Students\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            s.add();
            break;
        case 2:
            s.search();
            break;
        case 3:
            s.append();
            break;
        case 4:
            s.del();
            break;
        case 5:
            s.display();
            break;
        case 6:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice entered.\n";
        }
    } while (choice != 6);

    return 0;
}
