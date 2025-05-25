#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeToFile(const string& filename) {
    ofstream outfile(filename); 
    if (!outfile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    string data;
    cout << "Enter text to write to the file (end with a blank line):" << endl;
    cin.ignore();
    while (true) {
        getline(cin, data);
        if (data.empty()) break;
        outfile << data << endl;
    }
    outfile.close();
    cout << "Data written successfully!" << endl;
}

void appendToFile(const string& filename) {
    ofstream outfile(filename, ios::app); 
    if (!outfile) {
        cerr << "Error opening file for appending!" << endl;
        return;
    }

    string data;
    cout << "Enter text to append to the file (end with a blank line):" << endl;
    cin.ignore(); 
    while (true) {
        getline(cin, data);
        if (data.empty()) break;
        outfile << data << endl;
    }
    outfile.close();
    cout << "Data appended successfully!" << endl;
}

void readFromFile(const string& filename) {
    ifstream infile(filename); 
    if (!infile) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    string line;
    cout << "\nFile Contents:\n--------------\n";
    while (getline(infile, line)) {
        cout << line << endl;
    }
    infile.close();
}

int main() {
    string filename = "filedata.txt";
    int choice;

    do {
        cout << "\n====== File Management Tool ======" << endl;
        cout << "1. Write to File\n2. Append to File\n3. Read from File\n4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: writeToFile(filename); break;
            case 2: appendToFile(filename); break;
            case 3: readFromFile(filename); break;
            case 4: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
