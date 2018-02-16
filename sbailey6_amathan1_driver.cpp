#include "sbailey6_amathan1_entry.hpp"
#include "sbailey6_amathan1_phone_directory.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#define INSERT 1
#define SEARCH 2
#define DELETE 3
#define SHOW_DIRECTORY 4
#define EXIT 5

void menu(PhoneDirectory *phonebook){
	std::string in;
	int action = -1;
	
	
	while(action != EXIT){
		std::cout << "\nEnter a command.\nChoose from [\"Insert(press 1)\" \"Search(press 2)\" \"Delete(press 3)\" \"Show Directory(press 4)\"  \"Exit(press 5)\"]\n:";
		
		getline(std::cin, in);
		if(in.find_first_not_of("0123456789") != std::string::npos){
			std::cout << "Command needs to be numeric. Please Try again.\n";
			continue;
		}
		else action = atoi(in.c_str());
		if(action == INSERT){
			std::string first, phoneNum;
			std::cout << "Enter the name:\n";
			getline(std::cin, first);
			std::cout << "Enter the phone number:\n";
			getline(std::cin, phoneNum);
			if(phoneNum.length() != 13 || (phoneNum.substr(1, 3) + phoneNum.substr(5, 3) + phoneNum.substr(9, 4)).find_first_not_of("0123456789") != std::string::npos){
				std::cout << "Phone number should be of form (XXX)XXX-XXXX where X is a number" << std::endl;
				continue;
			}			
			phonebook->insertEntry((char *) first.c_str(), (char *) phoneNum.c_str());
		}
		else if(action == SEARCH){
			std::string name;
			std::cout << "Enter the name:\n";
			getline(std::cin, name);
			phonebook->searchDirectory((char *) name.c_str());		
		}
		else if(action == DELETE){
			std::string name;
			std::cout << "Enter the name:\n";
			getline(std::cin, name);
			phonebook->deleteEntry((char *) name.c_str());
		}

		else if(action == SHOW_DIRECTORY){
			std::cout << "-----------PHONE DIRECTORY---------------" << std::endl;
			for(int i = 0; i < phonebook->entries.size(); i++){
				std::cout << phonebook->entries[i]->getFirstName() << " "  
				<< phonebook->entries[i]->getLastName() << " " 
				<< phonebook->entries[i]->getPhoneNum() << std::endl;
			}
			std::cout << "----------------------------------------" << std::endl;
		}

		else if(action == EXIT){
			break;
		}
		else{
			std::cout << "Command not recognized. Please Try again.\n";
		}
	} 
}

int main(int argc, char** argv){
	if(argc != 2){
		std::cout << "usage: " << argv[0] << " <phone-directory>" << std::endl;
		exit(0);
	}
	
	PhoneDirectory *phonebook = new PhoneDirectory(argv[1]);
	phonebook->sortDirectory();
	menu(phonebook);
	
	delete phonebook;
	
	return 0;
}
