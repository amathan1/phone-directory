#include "Entry.hpp"
#include "PhoneDirectory.hpp"
#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char** argv){
	if(argc != 2){
		std::cout << "usage: " << argv[0] << " <phone-directory>" << std::endl;
		exit(0);
	}
	
	PhoneDirectory *phonebook = new PhoneDirectory(argv[1]);
	phonebook->searchDirectory("Com Miller");
	delete phonebook;
	
	return 0;
}
