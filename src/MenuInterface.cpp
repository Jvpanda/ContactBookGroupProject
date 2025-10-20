#include "MenuInterface.h"
#include "Contact.h"
#include <ios>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

MenuInterface::MenuInterface() {}
MenuInterface::~MenuInterface() {}

void MenuInterface::runMainMenuController() {
    int input = 1;
    do {
        input = Utils::validateUserInput(0, 11, menuList);
        switch (input) {
            case 0:
                return;
                break;
            case 1:
                CSV.loadCSV(currentBook);
                break;
            case 2:
                CSV.saveCSV(currentBook);
                break;
            case 3:
                currentBook.addContact();
                break;
            case 4:
                editMenu();
                break;
            case 5:
                {
                    int id = Utils::validateUserInput(0, 2147483647,
                                               "Choose an ID to delete: ");
                    currentBook.deleteContact(id);
                }
                break;
            case 6:
                currentBook.listContacts();
                break;
            case 7:
                searchMenu();
                break;
            case 8:
                filterMenu();
                break;
            case 9:
                {
                    ContactType type = getTypeFromInput();
                    currentBook.listContactsByType(type);
                }
                break;
            case 10:
                currentBook.showContactsMissingInfo();
                break;
            case 11:
                currentBook.displayGroupSummaries();
                break;
        }
    } while (input != 0);
}

ContactType MenuInterface::getTypeFromInput() {
    ContactType type;
    type = (ContactType)Utils::validateUserInput(
        1, 4,
        "Enter Contact Type:\n1 - Person\n2 - "
        "Business\n3 - Vendor\n4 - Emergency\nType: ");
    return type;
}

void MenuInterface::searchMenu() {
    string search;
    int searchChoice =
        Utils::validateUserInput(1, 4,
                          "Search by:\n1 - Name\n2 - Email\n3 - Phone "
                          "Number\nEnter: ");
    cout << "Please enter your search: ";
    getline(cin, search);
    switch (searchChoice) {
        case 1:
            currentBook.searchContactByName(search);
            break;
        case 2:
            currentBook.searchContactByEmail(search);
            break;
        case 3:
            currentBook.searchContactByPhone(search);
            break;
    }
}

void MenuInterface::filterMenu() {
    string filter;
    int filterChoice = Utils::validateUserInput(
        1, 3, "Filter by:\n1 - City\n2 - Tag\n3 - Type\nEnter: ");
    switch (filterChoice) {
        case 1:
            cout << "Please enter the city: ";
            getline(cin, filter);
            currentBook.filterByCity(filter);
            break;
        case 2:
            cout << "Please enter the Tag: ";
            getline(cin, filter);
            currentBook.filterByTag(filter);
            break;
        case 3:
            ContactType type = getTypeFromInput();
            currentBook.filterByType(type);
            break;
    }
}
void MenuInterface::editMenu() {
    int id         = Utils::validateUserInput(0, 2147483647, "Choose an ID to edit: ");
    int editChoice = Utils::validateUserInput(1, 5,
                                       "Edit:\n1 - Name\n2 - Email\n3 - Phone "
                                       "Number\n4 - City\n5 - Type\nEnter: ");
    string newData;
    switch (editChoice) {
        case 1:
            cout << "New Name: ";
            getline(cin, newData);
            currentBook.editName(id, newData);
            break;
        case 2:
            cout << "New Email: ";
            getline(cin, newData);
            currentBook.editEmail(id, newData);
            break;
        case 3:
            cout << "New Phone Number: ";
            getline(cin, newData);
            currentBook.editPhoneNumber(id, newData);
            break;
        case 4:
            cout << "New City: ";
            getline(cin, newData);
            currentBook.editCity(id, newData);
            break;
        case 5:
            ContactType type = getTypeFromInput();
            currentBook.editType(id, (int)type);
            break;
    }
}
