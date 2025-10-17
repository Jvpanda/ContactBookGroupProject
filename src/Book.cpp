#include "Book.h"

void Book::searchContactByName(const std::string& name)
{
	for (const Contact& contact : m_contacts)
	{
		if (contact.getName() == name)
			std::cout << contact << "\n";
	}
}
void Book::searchContactByEmail(const std::string& email)
{
	for (const Contact& contact : m_contacts)
	{
		if (contact.getEmail() == email)
			std::cout << contact << "\n";
	}
}
void Book::searchContactByPhone(const std::string& phoneNumber)
{
	for (const Contact& contact : m_contacts)
	{
		if (contact.getPhoneNumber() == phoneNumber)
			std::cout << contact << "\n";
	}
}

void Book::filterByType(ContactType type)
{
	for (const Contact& contact : m_contacts)
	{
		if (contact.getType() == type)
			std::cout << contact << "\n";
	}
}

void Book::filterByCity(const std::string& city)
{
	for (const Contact& contact : m_contacts)
	{
		if (contact.getCity() == city)
			std::cout << contact << "\n";
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
				std::cout << contact << "\n";
				break;
			}
		}
	}
}