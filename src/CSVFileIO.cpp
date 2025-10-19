#include "CSVFileIO.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

void CSVHandler::loadCSV(Book &currentBook) {
    ifstream inputFile;
    string filepath;

    cout << "Please select a file to load: ";
    getline(cin, filepath);

    inputFile.open(filepath.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    string id, name, email, phoneNumber, city, contactTypeString, tag;
    string line;

    while (getline(inputFile, line)) {
        Contact currentContact;
        stringstream lineSS(line);

        getline(lineSS, id, ',');
        getline(lineSS, name, ',');
        getline(lineSS, email, ',');
        getline(lineSS, phoneNumber, ',');
        getline(lineSS, city, ',');
        getline(lineSS, contactTypeString, ',');
        currentContact.setId(stoi(id));
        currentContact.setName(name);
        currentContact.setEmail(email);
        currentContact.setPhoneNumber(phoneNumber);
        currentContact.setCity(city);
        currentContact.setType((ContactType)stoi(contactTypeString));
        while (getline(lineSS, tag, ',')) {
            currentContact.addTag(tag);
        }
        currentBook.addContact(currentContact);
    }

    inputFile.close();
    cout << "File Successfully Loaded\n\n";
}

void CSVHandler::saveCSV(const Book &currentBook) {
    ofstream outputFile;
    string filepath;

    cout << "Please specify a file to save to: ";
    getline(cin, filepath);

    outputFile.open(filepath.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    for (const Contact &contact : currentBook.getContacts()) {
        outputFile << contact.getId() << ",";
        outputFile << contact.getName() << ",";
        outputFile << contact.getEmail() << ",";
        outputFile << contact.getPhoneNumber() << ",";
        outputFile << contact.getCity() << ",";
        outputFile << (int)contact.getType() << ",";
        for (const string &tag : contact.getTags()) {
            outputFile << tag << ",";
        }
        outputFile << '\n';
    }

    outputFile.close();
    cout << "File Successfully Saved\n\n";
}
