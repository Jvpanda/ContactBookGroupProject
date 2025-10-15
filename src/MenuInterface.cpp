#include "MenuInterface.h"
#include <ios>
#include <iostream>
#include <limits>
using namespace std;

MenuInterface::MenuInterface(){}
MenuInterface::~MenuInterface(){}

void MenuInterface::runMainMenuController(){
    short input = validateUserInput(0, 11, menuList);
    switch(input){
        case 0:
            return;
        break;
        case 1:
        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        break;
        case 5:
        break;
        case 6:
        break;
        case 7:
        break;
        case 8:
        break;
        case 9:
        break;
        case 10:
        break;
        case 11:
        break;
    }
}

short MenuInterface::validateUserInput(const short lowerBound,
                                         const short upperBound,
                                         const std::string menuOptions) const {
    bool valid;
    short input;
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

    return input;
}
