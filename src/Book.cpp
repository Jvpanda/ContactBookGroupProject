#include "Book.h"

void Book::searchContactByName(const std::string& name)
{
	for (const Contact& contact : m_contacts)
	{
		if (contact.getName() == name)
		{
			contact.printDetails();
			std::cout << "\n";
		}
	}
}
void Book::searchContactByEmail(const std::string& email)
{
	for (const Contact& contact : m_contacts)
	{
		if (contact.getEmail() == email)
		{
			contact.printDetails();
			std::cout << "\n";
		}
	}
}
void Book::searchContactByPhone(const std::string& phoneNumber)
{
	for (const Contact& contact : m_contacts)
	{
		if (contact.getPhoneNumber() == phoneNumber)
		{
			contact.printDetails();
			std::cout << "\n";
		}
	}
}

void Book::filterByType(ContactType contactType)
{
	for (const Contact& contact : m_contacts)
	{
		if (contact.getContactType() == contactType)
		{
			contact.printDetails();
			std::cout << "\n";
		}
	}
}

void Book::filterByCity(const std::string& city)
{
	for (const Contact& contact : m_contacts)
	{
		if (contact.getCity() == city)
		{
			contact.printDetails();
			std::cout << "\n";
		}
	}
}

void Book::filterByTag(const std::string& tag)
{
	for (const Contact& contact : m_contacts)
	{
		for (const std::string& contactTag : contact.getTags())
		{
			if (contactTag == tag)
			{
				contact.printDetails();
				std::cout << "\n";
				break;
			}
		}
	}
}