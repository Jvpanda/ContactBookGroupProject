#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <vector>
#include <iostream>

enum class ContactType
{
	Person = 1, Business, Vendor, Emergency
};

class Contact
{

public:
	Contact(const std::string& name, const std::string& email, const std::string& phoneNumber,
		const std::string& city, ContactType contactType);

	void addTag(const std::string& tag);
	void removeTag(const std::string& tag);
	void printDetails()const;

	int getId()const;
	const std::string& getName()const;
	const std::string& getEmail()const;
	const std::string& getPhoneNumber()const;
	const std::string& getCity()const;
	ContactType getContactType()const;
	std::string getContactTypeString()const;
	const std::vector<std::string>& getTags()const;

	void setName(const std::string& newName);
	void setEmail(const std::string& newEmail);
	void setPhoneNumber(const std::string& newPhoneNumber);
	void setCity(const std::string& newCity);
	void setContactType(ContactType newContactType);

private:
	int m_id;
	std::string m_name;
	std::string m_email;
	std::string m_phoneNumber;
	std::string m_city;
	ContactType m_contactType;
	std::vector<std::string> m_tags;

private:
	static int id;


};

#endif
