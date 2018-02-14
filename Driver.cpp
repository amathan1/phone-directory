#include "Entry.hpp"
#include "PhoneDirectory.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

int main(int argc, char** argv){
	if(argc != 2){
		std::cout << "usage: " << argv[0] << " <phone-directory>" << std::endl;
		exit(0);
	}
	
	PhoneDirectory *phonebook = new PhoneDirectory(argv[1]);
	phonebook->deleteEntry("Tom Miller");
	phonebook->searchDirectory("Tom Miller");
	phonebook->searchDirectory("Jason Smith");
	phonebook->insertEntry("Tom Piller", "(123)123-4444");
	phonebook->searchDirectory("Tom Piller");
	phonebook->sortDirectory();
	
	delete phonebook;
	
	return 0;
}
