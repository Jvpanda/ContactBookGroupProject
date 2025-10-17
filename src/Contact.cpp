#include "Contact.h"
using namespace std;

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
		<< "\nTags:";

	for (const std::string& tag : contact.tags)
		os << " " << tag;

	os << "\n-------------------------\n";
	return os;
}
