#ifndef CSV_IO_H
#define CSV_IO_H
#include "Book.h"

class CSVHandler {
    public:
    void loadCSV(Book &currentBook);
    void saveCSV(const Book &currentBook);

};
#endif
