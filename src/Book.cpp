#include "Book.h"

// ----------------
//  Getters
// ----------------

const std::vector<Contact>& Book::getContacts()const
{
	return contacts;
}


// Helper function to reduce duplicate code 
Contact* Book::getContactById(int id)
{
	for (int i = 0; i < contacts.size(); ++i)
	{
		if (contacts[i].getId() == id)
			return &contacts[i];
	}
	return nullptr;
}

// ----------------
//  Adding
// ----------------

void Book::addContact()
{
	int id = 0;
	std::string name, email, phoneNumber, city;
	int contactTypeInt;
	ContactType contactType;

	std::cout << "Enter ID: ";
	std::cin >> id;
	std::cin.ignore();
	std::cout << "Enter Name: ";
	std::getline(std::cin, name);

	std::cout << "Enter Email: ";
	std::getline(std::cin, email);

	std::cout << "Enter Phone Number: ";
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

	Contact contact{ id, name, email, phoneNumber, city, contactType };

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

// ----------------
//  Editing
// ----------------

void Book::editName(int id, const std::string& newName)
{
	Contact* contact = getContactById(id);
	if (contact == nullptr)
		std::cout << "Error: Invalid Id\n";
	else
		contact->setName(newName);
}

void Book::editEmail(int id, const std::string& newEmail)
{
	Contact* contact = getContactById(id);
	if (contact == nullptr)
		std::cout << "Error: Invalid Id\n";
	else
		contact->setEmail(newEmail);
}

void Book::editPhoneNumber(int id, const std::string& newPhoneNumber)
{
	Contact* contact = getContactById(id);
	if (contact == nullptr)
		std::cout << "Error: Invalid Id\n";
	else
		contact->setPhoneNumber(newPhoneNumber);
}

void Book::editCity(int id, const std::string& newCity)
{
	Contact* contact = getContactById(id);
	if (contact == nullptr)
		std::cout << "Error: Invalid Id\n";
	else
		contact->setCity(newCity);
}

void Book::editType(int id, int typeAsInt)
{
	Contact* contact = getContactById(id);
	if (contact == nullptr)
		std::cout << "Error: Invalid Id\n";
	else
	{
		switch (typeAsInt)
		{
		case 1:
			contact->setType(ContactType::Person);
			break;
		case 2:
			contact->setType(ContactType::Business);
			break;
		case 3:
			contact->setType(ContactType::Vendor);
			break;
		case 4:
			contact->setType(ContactType::Emergency);
			break;
		default:
			std::cout << "Error: Invalid Type\n";
			break;
		}
	}
}

// ----------------
//  Misc
// ----------------

void Book::deleteContact(int id)
{
	for (auto it = contacts.begin(); it != contacts.end(); it++)
	{
		if (it->getId() == id)
		{
			contacts.erase(it);
			return;
		}
	}
}

void Book::printIndividualDetails(int id) const
{
	for (const Contact& contact : contacts)
	{
		if (contact.getId() == id)
		{
			std::cout << contact;
			return;
		}
	}
}

void Book::listContacts() const
{
	for (const Contact& contact : contacts)
	{
		std::cout << contact;
	}
}

void Book::listContactsByType(ContactType type)const
{
	for (const Contact& contact : contacts)
	{
		if (contact.getType() == type)
		{
			std::cout << contact;
		}
	}
}

void Book::showContactsMissingInfo()const
{
	for (const Contact& contact : contacts)
	{
		if (contact.getEmail().empty() || contact.getPhoneNumber().empty() ||
			contact.getCity().empty())
		{
			std::cout << contact;
		}
	}
}

void Book::displayGroupSummaries()const
{
	int personCount = 0, businessCount = 0, vendorCount = 0, emergencyCount = 0;

	for (const Contact& contact : contacts)
	{
		if (contact.getType() == ContactType::Person)
			personCount++;
		else if (contact.getType() == ContactType::Business)
			businessCount++;
		else if (contact.getType() == ContactType::Vendor)
			vendorCount++;
		else if (contact.getType() == ContactType::Emergency)
			emergencyCount++;
	}

	std::cout << "Group Summaries:\n";
	std::cout << "Persons: " << personCount << std::endl;
	std::cout << "Businesses: " << businessCount << std::endl;
	std::cout << "Vendors: " << vendorCount << std::endl;
	std::cout << "Emergencies: " << emergencyCount << std::endl;
}

// ----------------
//  Searches
// ----------------

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

// ----------------
//  Filters
// ----------------

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
