#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class to represent a Record
class Record {
private:
    string name;
    int year;
    string place;
    char gender;
    string fatherName;
    string motherName;
    string notes;

public:
    // Constructor
    Record(const string& _name = "", int _year = 0,
        const string& _place = "", char _gender = ' ', const
        string& _fatherName = "", const string& _motherName = "", const string& _notes = "")
        : name(_name), year(_year), place(_place), gender(_gender),
        fatherName(_fatherName), motherName(_motherName), notes(_notes) {}

    // Getter methods
    string getName() const { return name; }
    int getYear() const { return year; }
    string getPlace() const { return place; }
    char getGender() const { return gender; }
    string getFatherName() const { return fatherName; }
    string getMotherName() const { return motherName; }
    string getNotes() const { return notes; }

    // Setter methods
    void setName(const string& _name) { name = _name; }
    void setYear(int _year) { year = _year; }
    void setPlace(const string& _place) { place = _place; }
    void setGender(char _gender) { gender = _gender; }
    void setFatherName(const string& _fatherName) { fatherName = _fatherName; }
    void setMotherName(const string& _motherName) { motherName = _motherName; }
    void setNotes(const string& _notes) { notes = _notes; }

    // Overloaded insertion operator for output stream
    friend ostream& operator<<(ostream& os, const Record& record) {
        os << "Name: " << record.name << ", Year: " << record.year << ", Place: " << record.place
            << ", Gender: " << record.gender << ", Father's Name: " << record.fatherName
            << ", Mother's Name: " << record.motherName << ", Notes: " << record.notes;
        return os;
    }
};

// Function prototypes
void addRecord(vector<Record>& records, const string& recordType);
void displayRecords(const vector<Record>& records);
void searchRecord(const vector<Record>& records, const string& searchName);
void editRecord(vector<Record>& records, const string& searchName);
void deleteRecord(vector<Record>& records, const string& searchName);

// Function to add a record (birth or death)
void addRecord(vector<Record>& records, const string& recordType) {
    int numRecords;
    cout << "Enter the number of " << recordType << " records you want to add: ";
    cin >> numRecords;

    for (int i = 0; i < numRecords; ++i) {
        string name, place, fatherName, motherName, notes;
        int year;
        char gender;

        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter " << recordType << " year: ";
        cin >> year;

        cout << "Enter " << recordType << " place: ";
        cin.ignore();
        getline(cin, place);

        cout << "Enter gender (M/F): ";
        cin >> gender;
        while (gender != 'M' && gender != 'F') {
            cout << "Invalid input. Please enter 'M' for Male or 'F' for Female: ";
            cin >> gender;
        }

        cout << "Enter father's name: ";
        cin.ignore();
        getline(cin, fatherName);

        cout << "Enter mother's name: ";
        getline(cin, motherName);

        cout << "Enter any additional notes: ";
        getline(cin, notes);

        Record newRecord(name, year, place, gender, fatherName, motherName, notes);
        records.push_back(newRecord);
        cout << "Record added successfully." << endl;
    }
}

// Function to display all records
void displayRecords(const vector<Record>& records) {
    cout << "\n--- Records ---" << endl;
    for (const auto& record : records) {
        cout << record << endl;
    }
}

// Function to search for a record by name
void searchRecord(const vector<Record>& records, const string& searchName) {
    cout << "\n--- Search Records ---" << endl;
    bool found = false;
    for (const auto& record : records) {
        if (record.getName() == searchName) {
            cout << record << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No record found for " << searchName << endl;
    }
}

// Function to edit a record by name
void editRecord(vector<Record>& records, const string& searchName) {
    bool found = false;
    for (auto& record : records) {
        if (record.getName() == searchName) {
            string newName, newPlace, newFatherName, newMotherName, newNotes;
            int newYear;
            char newGender;

            cout << "Enter new name (or press Enter to keep the same): ";
            cin.ignore();
            getline(cin, newName);
            if (!newName.empty()) {
                record.setName(newName);
            }

            cout << "Enter new year: ";
            cin >> newYear;

            cout << "Enter new place: ";
            cin.ignore();
            getline(cin, newPlace);

            cout << "Enter new gender (M/F): ";
            cin >> newGender;

            cout << "Enter new father's name: ";
            cin.ignore();
            getline(cin, newFatherName);

            cout << "Enter new mother's name: ";
            getline(cin, newMotherName);

            cout << "Enter new notes: ";
            getline(cin, newNotes);

            record.setYear(newYear);
            record.setPlace(newPlace);
            record.setGender(newGender);
            record.setFatherName(newFatherName);
            record.setMotherName(newMotherName);
            record.setNotes(newNotes);

            cout << "Record updated successfully." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No record found for " << searchName << endl;
    }
}

// Function to delete a record by name
void deleteRecord(vector<Record>& records, const string& searchName) {
    bool found = false;
    for (auto it = records.begin(); it != records.end(); ++it) {
        if (it->getName() == searchName) {
            records.erase(it);
            cout << "Record deleted successfully." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No record found for " << searchName << endl;
    }
}

int main() {
    vector<Record> records;
    int choice;
    bool recordsAdded = false;

    // Display project information
    cout << "\t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t\t Ganpat University" << endl;
    cout << "\t\t\t\t\t Institute of Computer Technology" << endl;
    cout << "\t\t\t\t\t B.Tech Computer Science and Engineering" << endl;
    cout << "\t\t\t\t\t" << endl;
    cout << endl;
    cout << "Name: SWAYAM HIRANI" << endl;
    cout << "Branch: CSE" << endl;
    cout << "Batch: 22 A" << endl;
    cout << "Project Topic: BIRTH AND DEATH REGISTRATION SYSTEM" << endl;
    cout << endl;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Birth Record\n";
        cout << "2. Add Death Record\n";
        cout << "3. Display Records\n";
        cout << "4. Search Record\n";
        cout << "5. Edit Record\n";
        cout << "6. Delete Record\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
        case 2:
            if (!recordsAdded || records.size() < 5) {
                addRecord(records, (choice == 1) ? "birth" : "death");
                recordsAdded = true;
            } else {
                cout << "You have already added 5 records. Cannot add more." << endl;
            }
            break;

        case 3:
            displayRecords(records);
            break;

        case 4: {
            string searchName;
            cout << "Enter name to search: ";
            cin.ignore();
            getline(cin, searchName);
            searchRecord(records, searchName);
            break;
        }

        case 5: {
            string searchName;
            cout << "Enter name to edit: ";
            cin.ignore();
            getline(cin, searchName);
            editRecord(records, searchName);
            break;
        }

        case 6: {
            string searchName;
            cout << "Enter name to delete: ";
            cin.ignore();
            getline(cin, searchName);
            deleteRecord(records, searchName);
            break;
        }

        case 7:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
        }

    } while (choice != 7);

    return 0;
}
