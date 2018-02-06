#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>
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
		//std::cout << "name: " << lastName << "\nnumber: " << pNum << std::endl;
		std::getline(in, token);
	}	
}

void PhoneDirectory::sortDirectory(){

}

//use binary search. assumes the directory is already sorted.
void PhoneDirectory::searchDirectory(char* name){
	searchDirectory(name, 0, this->entries.size()-1);
}

//helper method called to make the binary search easier
void PhoneDirectory::searchDirectory(char* name, int low, int high){
	int mid;
	if(low > high){
		std::cout << "Name not found" << std::endl;
		return;
	}
	else{
	 	mid = (low+high) / 2;
	 	std::string nm(name);
	 	std::string first(this->entries[mid]->getFirstName());
	 	std::string last(this->entries[mid]->getLastName());
	 	std::string fullName = first + " " + last;
	 	if(nm.compare(fullName) == 0){
	 		//print the found and same named people to the right
	 		int next = 0;
	 		do{
	 			std::cout << "location: " << mid + next + 1
				<< "\tfull name: \"" << fullName
				<< "\"\tphone number: \"" 
				<< this->entries[mid+next]->getPhoneNum() 
				<< "\"" << std::endl;
				next++;
				if(mid + next < this->entries.size()){
					first = std::string(this->entries[mid+next]
					->getFirstName());
					last = std::string(this->entries[mid+next]
					->getLastName());
					fullName = first + " " + last;
				}
				else break;
			}while(nm.compare(fullName) == 0);
			
			//print same named people to the left
			int prev = 1;
			if(mid - prev >= 0){
					first = std::string(this->entries[mid-prev]
					->getFirstName());
					last = std::string(this->entries[mid-prev]
					->getLastName());
					fullName = first + " " + last;
					
				while(nm.compare(fullName) == 0){
					std::cout << "location: " << mid -prev + 1
					<< "\tfull name: \"" << fullName
					<< "\"\tphone number: \"" 
					<< this->entries[mid-prev]->getPhoneNum() 
					<< "\"" << std::endl;
					prev++;
					if(mid - prev >= 0){
						first = std::string(this->entries[mid-prev]
						->getFirstName());
						last = std::string(this->entries[mid-prev]
						->getLastName());
						fullName = first + " " + last;
					}
					else break;
				}
			}
			return;
		}
		else if(nm.compare(fullName) < 0) return searchDirectory(name, low, mid-1);
		else return searchDirectory(name, mid+1, high);
	}
}

void PhoneDirectory::deleteEntry(char* name){

}

void PhoneDirectory::insertEntry(char* name, char* phone_number){

}
