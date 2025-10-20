#ifndef BOOK_H
#define BOOK_H

#include "Contact.h"
#include "Utils.h"
#include <type_traits>

class Book
{

public:
	const std::vector<Contact>& getContacts()const;

	void addContact();
	void addContact(const Contact& contact);

	void editName(int id, const std::string& newName);
	void editEmail(int id, const std::string& newEmail);
	void editPhoneNumber(int id, const std::string& newPhoneNumber);
	void editCity(int id, const std::string& newCity);
	void editType(int id, int typeAsInt);

	void deleteContact(int id);
	void printIndividualDetails(int id)const;

	void listContacts()const;
	void listContactsByType(ContactType contactType)const;

	void showContactsMissingInfo()const;

	void displayGroupSummaries()const;

	void searchContactByName(const std::string& name);
	void searchContactByEmail(const std::string& email);
	void searchContactByPhone(const std::string& phoneNumber);

	void filterByType(ContactType contactType);
	void filterByCity(const std::string& city);
	void filterByTag(const std::string& tag);

private:
	std::vector<Contact> contacts;

private:
	Contact* getContactById(int id);

};

#endif
