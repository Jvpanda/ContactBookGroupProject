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
        input = validateUserInput(0, 11, menuList);
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
                // currentBook.editContact(id)
                break;
            case 5:
                {
                    // int id = validateUserInput(0, 2147483647,
                    // "Choose an ID to delete: ");
                    // currentBook.deleteContact(id);
                }
                break;
            case 6:
                // currentBook.listContacts();
                break;
            case 7:
                searchMenu();
                break;
            case 8:
                filterMenu();
                break;
            case 9:
                { /*
                    ContactType type = getTypeFromInput();
                     currentBook.listContactsByType(type);
                     */
                }
                break;
            case 10:
                // currentBook.showContactsMissingInfo();
                break;
            case 11:
                // currentBook.displayGroupSummaries();
                break;
        }
    } while (input != 0);
}

int MenuInterface::validateUserInput(const int lowerBound, const int upperBound,
                                     const std::string menuOptions) const {
    bool valid;
    int input;
    streamsize maxCharLimit = numeric_limits<streamsize>::max();

    valid = false;
    input = -1;

    do {
        cout << menuOptions;
        if (!(cin >> input)) {
            cin.clear();
            cin.ignore(maxCharLimit, '\n');
            valid = false;
            cout << "\n**** Please enter a NUMBER between " << lowerBound << "-"
                 << upperBound << " ****\n\n";
        } else if (input < lowerBound || input > upperBound) {
            cin.ignore(maxCharLimit, '\n');
            valid = false;
            cout << "\n**** The number " << input
                 << " is an invalid entry ****";
            cout << "\n**** Please enter a number between " << lowerBound << "-"
                 << upperBound << " ****\n\n";
        } else {
            valid = true;
        }

    } while (!valid);
    cin.ignore(1, '\n');

    return input;
}

ContactType MenuInterface::getTypeFromInput() {
    ContactType type;
    type = (ContactType)validateUserInput(
        1, 4,
        "Enter Contact Type (1 = Person, 2 = "
        "Business, 3 = Vendor, 4 = Emergency): ");
    return type;
}

void MenuInterface::searchMenu() {
    string search;
    int searchChoice =
        validateUserInput(1, 4,
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
    int searchChoice = validateUserInput(
        1, 4, "Filter by:\n1 - City\n2 - Tag\n3 - Type\nEnter: ");
    switch (searchChoice) {
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
