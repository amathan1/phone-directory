make: all

all: Driver.o PhoneDirectory.o Entry.o
	g++ -g sbailey6_amathan1_driver.o sbailey6_amathan1_phone_directory.o sbailey6_amathan1_entry.o -o sbailey6_amathan1_phone_directory.out #-std=c++11

Driver.o: sbailey6_amathan1_driver.cpp
	g++ -g -c sbailey6_amathan1_driver.cpp

PhoneDirectory.o: sbailey6_amathan1_phone_directory.cpp
	g++ -g -c sbailey6_amathan1_phone_directory.cpp

Entry.o: sbailey6_amathan1_entry.cpp
	g++ -g -c sbailey6_amathan1_entry.cpp

clean: 
	rm -f *.o sbailey6_amathan1_phone_directory.out
