#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H
#include "Book.h"
#include "CSVFileIO.h"
#include <string>

class MenuInterface {
    public:
        MenuInterface();
        ~MenuInterface();
        CSVHandler CSV;

        void runMainMenuController();
        Book &getCurrentBook();

    private:
        Book currentBook;

        int validateUserInput(const int lowerBound, const int upperBound,
                              const std::string menuOptions) const;
        ContactType getTypeFromInput();
        void searchMenu();
        void filterMenu();
        void editMenu();

        const std::string menuList = "0 - Exit\n"
                                     "1 - Load New File\n"
                                     "2 - Save New File\n"
                                     "3 - Add Contact\n"
                                     "4 - Edit Existing Contact\n"
                                     "5 - Delete Contact\n"
                                     "6 - List All Contacts\n"
                                     "7 - Search Contacts\n"
                                     "8 - Filter Contacts\n"
                                     "9 - List Contacts By Type\n"
                                     "10 - List Contacts by Missing Info\n"
                                     "11 - Display Group Summaries\n"
                                     "Command: ";
};

#endif
