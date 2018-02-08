#ifndef _ENTRY_HPP_

#define _ENTRY_HPP_
#include<string>

class Entry{
	public:
		Entry(std::string firstName, std::string lastName, std::string phoneNum);
		~Entry();
		std::string getFirstName();
		std::string getLastName();
		std::string getPhoneNum();
		
	private:
		std::string firstName;
		std::string lastName;
		std::string phoneNum;		
};

#endif
