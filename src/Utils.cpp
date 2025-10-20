#include "Utils.h"
#include <iostream>

namespace Utils {

int validateUserInput(const int lowerBound, const int upperBound,
                      const std::string menuOptions) {
    bool valid;
    int input;
    constexpr std::streamsize maxCharLimit =
        std::numeric_limits<std::streamsize>::max();

    valid = false;
    input = -1;

    do {
        std::cout << menuOptions;
        if (!(std::cin >> input)) {
            std::cin.clear();
            std::cin.ignore(maxCharLimit, '\n');
            valid = false;
            std::cout << "\n**** Please enter a NUMBER between " << lowerBound
                      << "-" << upperBound << " ****\n\n";
        } else if (input < lowerBound || input > upperBound) {
            std::cin.ignore(maxCharLimit, '\n');
            valid = false;
            std::cout << "\n**** The number " << input
                      << " is an invalid entry ****";
            std::cout << "\n**** Please enter a number between " << lowerBound
                      << "-" << upperBound << " ****\n\n";
        } else {
            valid = true;
        }

    } while (!valid);
    std::cin.ignore(1, '\n');

    return input;
}

ContactType getTypeFromInput() {
    ContactType type;
    type = (ContactType)Utils::validateUserInput(
        1, 4,
        "Enter Contact Type:\n1 - Person\n2 - "
        "Business\n3 - Vendor\n4 - Emergency\nType: ");
    return type;
}

} // namespace Utils
