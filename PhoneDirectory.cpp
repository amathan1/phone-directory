#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "PhoneDirectory.hpp"

PhoneDirectory::PhoneDirectory(std::string filePath){
	create(filePath);
}

PhoneDirectory::~PhoneDirectory(){
	int entryNum = this->entries.size();
	for(int i = 0; i < entryNum; i++) delete this->entries[i];
}


void PhoneDirectory::create(std::string filePath){
	std::ifstream in;
	in.open(filePath);
	std::string token;
	std::getline(in, token);
	while(in){
		std::stringstream strStream;
		strStream << token;
		std::string firstName;
		std::string lastName;
		std::string pNum;
		getline(strStream, firstName, ' ');
		getline(strStream, lastName, ',');
		getline(strStream, pNum, ',');
		this->entries.push_back(new Entry(firstName, lastName, pNum));
		std::cout << "name: " << lastName << "\nnumber: " << pNum << std::endl;
		std::getline(in, token);
	}	
}

void PhoneDirectory::sortDirectory(){

}

void PhoneDirectory::searchDirectory(char* name){

}

void PhoneDirectory::deleteEntry(char* name){

}

void PhoneDirectory::insertEntry(char* name, char* phone_number){

}
