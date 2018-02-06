#include "Entry.hpp"

Entry::Entry(std::string firstName, std::string lastName, std::string phoneNum){

	this->firstName = firstName.c_str(); 
	this->lastName = lastName.c_str();
	this->phoneNum = phoneNum.c_str();
}

Entry::~Entry(){

}

const char* Entry::getFirstName(){
	return this->firstName;
}

const char* Entry::getLastName(){
	return this->lastName;
}

const char* Entry::getPhoneNum(){
	return this->phoneNum;
}
		
