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

void 
PhoneDirectory::sortDirectory()
{

	// Sort people with lastname as the key
	std::vector<std::string> last_names;
	std::vector<int> args;

	for (int i = 0; i < this->entries.size(); i++)
	{
		last_names.push_back(this->entries->at(i).getLastName());
		args.push_back(i);
	}

	merge_sort(last_names, args);

	std::vector<Entry> new_entries = new std::vector<Entry>;

	correct_them(args);

	for (int i = 0; i < args.size(); i++)



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


std::vector<std::string> 
PhoneDirectory::merge(std::vector<std::string> &arr1, std::vector<std::string> &arr2, std::vector<int> &arg1, std::vector<int> &arg2, std::vector<int> &arg)
{
	/* Recursive helper function */
	std::vector<std::string> arr;

	int c_i = arr1.size();
	int c_j = arr2.size();
	int i = 0, j = 0;

	while ((i < c_i) || (j < c_j))
	{
		if (i == c_i)
		{
			arr.push_back(arr2[j]);
			arg.push_back(arg2[j]);
			j++;
		}
		else if (j == c_j)
		{
			arr.push_back(arr1[i]);
			arg.push_back(arg2[i]);
			i++;
		}
		else if (arr1[i].compare(arr2[j]) < 0)
		{
			arr.push_back(arr1[i]);
			arg.push_back(arg1[i]);
			i++;
		}
		else
		{
			arr.push_back(arr2[j]);
			arg.push_back(arg2[j]);
			j++;
		}
	}
	return arr;
}


std::vector<std::string> 
PhoneDirectory::merge_sort(std::vector<std::string> arr0, std::vector<int> &args)
{	
	/*Mergesort: Takes a vector of string as input(Pass by value)
	 Returns sorted vector of strings */

	int size = arr0.size();
	if (size < 2)	return arr0;

	int med = size / 2;
	std::vector<std::string> arr1, arr2, out;
	std::vector<int> arg1, arg2, arg_o;

	for(int i = 0; i < size; ++i)
	{
		(i < med)?arr1.push_back(arr0[i]):arr2.push_back(arr0[i]);
		(i < med)?arg1.push_back(args[i]):arg2.push_back(args[i]);
	}

	arr1 = merge_sort(arr1, arg1);
	arr2 = merge_sort(arr2, arg2);
	out = merge(arr1, arr2, arg1, arg2, arg_o);

	args.clear();
	for (int i = 0; i < arg_o.size(); i++)	args.push_back(arg_o[i])

	return out;
}


int 
PhoneDirectory::partition(std::vector<int> &arr, int low, int high)
{
	/* Helper for quicksort */
	int pivot, i, j, temp;
	i = low - 1;
	pivot = rand() % high;

	while (pivot < low)
		pivot = rand() % high;

	temp = arr[pivot];
	arr[pivot] = arr[high - 1];
	arr[high-1] = temp;
	pivot = high -1;


	for (j = low; j < high - 1; ++j)
	{
		if (arr[j] < arr[pivot]){
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	i++;
	temp = arr[i];
	arr[i] = arr[pivot];
	arr[pivot] = temp;

	return i;
}



int 
PhoneDirectory::quick_sort(std::vector<int> &arr, int low, int high)
{
	/* Quicksort: Pass by reference vector of integers and by value 0 and vector.size() */

	int pivot;
	if (high - low < 2)	return 0;

	pivot = partition(arr, low, high);

	quick_sort(arr, low, pivot);
	quick_sort(arr, pivot, high);

	return 0;
}


int
correct_them(std::vector<int> &args)
{
	string temp_s = 
}