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

long Entry::getPhoneNum(){
	return std::stol(phoneNum.substr(1, 3), NULL, 10)*10000000 + 
		std::stol(phoneNum.substr(5, 3), NULL, 10)*10000 
		+ std::stol(phoneNum.substr(9, 4), NULL, 10);
}
		
