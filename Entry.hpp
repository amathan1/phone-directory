#ifndef _ENTRY_HPP_

#define _ENTRY_HPP_
#include<string>

class Entry{
	public:
		Entry(std::string firstName, std::string lastName, std::string phoneNum);
		~Entry();
		const char* getFirstName();
		const char* getLastName();
		const char* getPhoneNum();
		
	private:
		const char* firstName;
		const char* lastName;
		const char* phoneNum;
		
		
};

#endif
