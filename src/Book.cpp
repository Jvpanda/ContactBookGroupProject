#include "Book.h"

const std::vector<Contact>& Book::getContacts()const
{
	return contacts;
}

void Book::addContact()
{
	std::string name, email, phoneNumber, city;
	int contactTypeInt;
	ContactType contactType;

	std::cout << "Enter Name: ";
	std::getline(std::cin, name);

	std::cout << "Enter Email: ";
	std::getline(std::cin, email);

	std::cout << "Enter phoneNumber: ";
	std::getline(std::cin, phoneNumber);

	std::cout << "Enter City: ";
	std::getline(std::cin, city);

	std::cout << "Enter Contact Type (1 = Person, 2 = Business, 3 = Vendor, 4 = Emergency): ";
	std::cin >> contactTypeInt;
	std::cin.ignore();

	switch (contactTypeInt)
	{
	case 1:
		contactType = ContactType::Person;
		break;
	case 2:
		contactType = ContactType::Business;
		break;
	case 3:
		contactType = ContactType::Vendor;
		break;
	case 4:
		contactType = ContactType::Emergency;
		break;
	}

	Contact contact{ name, email, phoneNumber, city, contactType };

	std::cout << "Enter Tags (Enter Nothing To Stop): ";
	std::string currentTag{};
	do
	{
		std::getline(std::cin, currentTag);
		contact.addTag(currentTag);
	} while (!currentTag.empty());

	contacts.emplace_back(contact);

}

void Book::addContact(const Contact& contact)
{
	contacts.emplace_back(contact);
}

void Book::searchContactByName(const std::string& name)
{
	for (const Contact& contact : contacts)
	{
		if (contact.getName() == name)
			std::cout << contact << "\n";
	}
}
void Book::searchContactByEmail(const std::string& email)
{
	for (const Contact& contact : contacts)
	{
		if (contact.getEmail() == email)
			std::cout << contact << "\n";
	}
}
void Book::searchContactByPhone(const std::string& phoneNumber)
{
	for (const Contact& contact : contacts)
	{
		if (contact.getPhoneNumber() == phoneNumber)
			std::cout << contact << "\n";
	}
}

void Book::filterByType(ContactType type)
{
	for (const Contact& contact : contacts)
	{
		if (contact.getType() == type)
			std::cout << contact << "\n";
	}
}

void Book::filterByCity(const std::string& city)
{
	for (const Contact& contact : contacts)
	{
		if (contact.getCity() == city)
			std::cout << contact << "\n";
	}
}

void Book::filterByTag(const std::string& tag)
{
	for (const Contact& contact : contacts)
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