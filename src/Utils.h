#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "Contact.h"

namespace Utils {

    int validateUserInput(const int lowerBound, const int upperBound,
        const std::string menuOptions);

    ContactType getTypeFromInput();

}

#endif
