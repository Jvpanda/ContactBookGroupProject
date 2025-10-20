#include "Contact.h"
using namespace std;

Contact::Contact(const int id, const std::string& name, const std::string& email, const std::string& phoneNumber,
	const std::string& city, ContactType type)
	: id(id), name(name), email(email), phoneNumber(phoneNumber), city(city), type(type)
{ }

Contact::Contact() : id(0), name(""), email(""), phoneNumber(""), city(""), type(ContactType::Person) {}

int Contact::getId() const {
	return id;
}
const std::string& Contact::getName() const {
	return name;
}
const std::string& Contact::getEmail() const {
	return email;
}
const std::string& Contact::getPhoneNumber() const {
	return phoneNumber;
}
const std::string& Contact::getCity() const {
	return city;
}
ContactType Contact::getType() const {
	return type;
}
const std::vector<std::string>& Contact::getTags() const {
	return tags;
}

void Contact::setId(int newId) {
	id = newId;
}
void Contact::setName(const std::string& newName) {
	name = newName;
}
void Contact::setEmail(const std::string& newEmail) {
	email = newEmail;
}
void Contact::setPhoneNumber(const std::string& newNumber) {
	phoneNumber = newNumber;
}
void Contact::setCity(const std::string& newCity) {
	city = newCity;
}
void Contact::setType(ContactType newType) {
	type = newType;
}
void Contact::addTag(const std::string& newTag) {
	std::vector<std::string>::iterator it = find(tags.begin(), tags.end(), newTag);			// check if new tag already exists
	if (it == tags.end()) {																	// if not, add tag
		tags.push_back(newTag);
	}
}
void Contact::removeTag(const std::string& tagToRemove) {
	std::vector<std::string>::iterator it = find(tags.begin(), tags.end(), tagToRemove);	// locate desired tag if possible
	if (it != tags.end()) {																	// remove if it exists
		tags.erase(it);
	}
}

string Contact::getTypeAsString() const
{
	switch (type)
	{
	case ContactType::Person:
		return "Person";
	case ContactType::Business:
		return "Business";
	case ContactType::Vendor:
		return "Vendor";
	case ContactType::Emergency:
		return "Emergency";
	default:
		return "None";
	}
}

std::ostream& operator<<(std::ostream& os, const Contact& contact)
{
	os << "-------------------------"
		<< "\nID: " << contact.id
		<< "\nName: " << contact.name
		<< "\nEmail: " << contact.email
		<< "\nPhone Number: " << contact.phoneNumber
		<< "\nCity: " << contact.city
		<< "\nContact Type: " << contact.getTypeAsString()
		<< "\nTags: ";

	for (int i = 0; i < contact.tags.size(); ++i)
		os << contact.tags[i] << (i < contact.tags.size() - 1 ? ", " : "");

	os << "\n-------------------------\n";
	return os;
}
