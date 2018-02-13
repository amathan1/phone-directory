make: all

all: Driver.o PhoneDirectory.o Entry.o
	g++ -g Driver.o PhoneDirectory.o Entry.o -o phoneDirectory #-std=c++11

Driver.o: Driver.cpp
	g++ -g -c Driver.cpp

PhoneDirectory.o: PhoneDirectory.cpp
	g++ -g -c PhoneDirectory.cpp

Entry.o: Entry.cpp
	g++ -g -c Entry.cpp

clean: 
	rm -f *.o phoneDirectory
