#include "Entry.hpp"

Entry::Entry(std::string firstName, std::string lastName, std::string phoneNum){
	this->firstName = std::string(firstName); 
	this->lastName = std::string(lastName);
	this->phoneNum = std::string(phoneNum);
}

Entry::~Entry(){

}

std::string Entry::getFirstName(){
	return this->firstName;
}

std::string Entry::getLastName(){
	return this->lastName;
}

std::string Entry::getPhoneNum(){
	return this->phoneNum;
}
		
