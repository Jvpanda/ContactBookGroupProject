#ifndef BOOK_H
#define BOOK_H

#include "Contact.h"

class Book
{

public:
	const std::vector<Contact>& getContacts()const;

	void addContact();
	void addContact(const Contact& contact);

	void deleteContact(int id);
	void printIndividualDetails(int id)const;

	void listContacts()const;
	void listContactsByType(ContactType contactType)const;

	void showContactsMissingInfo()const;

	void searchContactByName(const std::string& name);
	void searchContactByEmail(const std::string& email);
	void searchContactByPhone(const std::string& phoneNumber);

	void filterByType(ContactType contactType);
	void filterByCity(const std::string& city);
	void filterByTag(const std::string& tag);

private:
	std::vector<Contact> contacts;

};

#endif
