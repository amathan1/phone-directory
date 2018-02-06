#include<vector>
#include<string> 

#include "Entry.hpp"

#ifndef _PHONEDIRECTORY_HPP_

#define _PHONEDIRECTORY_HPP_

class PhoneDirectory{
	public:
		PhoneDirectory(std::string filePath);
		~PhoneDirectory();

		void create(std::string filePath);
		void sortDirectory();
		void searchDirectory(char* name);
		void deleteEntry(char* name);
		void insertEntry(char* name, char* phone_number);
	private:
		std::vector<Entry*> entries;
};

#endif