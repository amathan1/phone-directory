#ifndef _ENTRY_HPP_

#define _ENTRY_HPP_
#include<string>

class Entry{
	public:
		Entry(std::string firstName, std::string lastName, long phoneNum);
		~Entry();
		std::string getFirstName();
		std::string getLastName();
		long getPhoneNum();
		
	private:
		std::string firstName;
		std::string lastName;
		long phoneNum;		
};

#endif
