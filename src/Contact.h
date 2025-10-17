#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

enum ContactType { Person, Business, Vendor, Emergency };

class Contact {
	public:
		// GETTERS
		int getId() const;
		const std::string& getName() const;
		const std::string& getEmail() const;
		const std::string& getPhoneNumber() const;
		const std::string& getCity() const;
		ContactType getType() const;
		std::string getTypeAsString() const;
		const std::vector<std::string>& getTags() const;

		// SETTERS
		void setId(int newId);
		void setName(const std::string& newName);
		void setEmail(const std::string& newEmail);
		void setPhoneNumber(const std::string& newNumber);
		void setCity(const std::string& newCity);
		void setType(ContactType newType);
		void addTag(const std::string& newTag);
		void removeTag(const std::string& tagToRemove);

		friend std::ostream& operator<<(std::ostream& os, const Contact& contact);

	private:
		int id;
		std::string name;
		std::string email;
		std::string phoneNumber;
		std::string city;
		ContactType type;
		std::vector<std::string> tags;
};
