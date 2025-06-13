#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void createFile(const string& filename);
void openAndEditFile(const string& filename);
void saveFile(const string& filename, const vector<string>& lines);

int main() {
    int choice;
    string filename;

    while (true) {
        cout << "\nText Editor Menu\n";
        cout << "1. Create New Document\n2. Open Existing Document\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // clear input buffer

        switch (choice) {
            case 1:
                cout << "Enter filename: ";
                getline(cin, filename);
                createFile(filename);
                break;
            case 2:
                cout << "Enter filename: ";
                getline(cin, filename);
                openAndEditFile(filename);
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice!";
        }
    }
}

void createFile(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Error creating file!\n";
        return;
    }
    cout << "Enter text (type 'EXIT' to finish):\n";
    string line;
    while (getline(cin, line)) {
        if (line == "EXIT") break;
        file << line << "\n";
    }
    file.close();
    cout << "File created successfully!\n";
}

void openAndEditFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "File not found!\n";
        return;
    }

    vector<string> lines;
    string line;
    cout << "\nCurrent Content:\n";
    while (getline(file, line)) {
        cout << line << endl;
        lines.push_back(line);
    }
    file.close();

    cout << "\nAdd new lines (type 'EXIT' to finish):\n";
    while (getline(cin, line)) {
        if (line == "EXIT") break;
        lines.push_back(line);
    }

    saveFile(filename, lines);
}

void saveFile(const string& filename, const vector<string>& lines) {
    ofstream file(filename);
    for (const auto& line : lines)
        file << line << "\n";
    file.close();
    cout << "File saved successfully!\n";
}