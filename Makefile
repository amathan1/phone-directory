make: all

all: Driver.o PhoneDirectory.o Entry.o
	g++ -g Driver.o PhoneDirectory.o Entry.o -o phoneDirectory

Driver.o: Driver.cpp
	g++ -g -c Driver.cpp

PhoneDirectory.o: PhoneDirectory.cpp
	g++ -g -c PhoneDirectory.cpp -std=c++11

Entry.o: Entry.cpp
	g++ -g -c Entry.cpp -std=c++11

clean:
	rm -f *.o phoneDirectory
