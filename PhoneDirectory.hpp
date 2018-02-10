#include<vector>
#include<string>

#include "Entry.hpp"

#ifndef _PHONEDIRECTORY_HPP_

#define _PHONEDIRECTORY_HPP_

class PhoneDirectory{
	public:
		PhoneDirectory(std::string filePath);
		~PhoneDirectory();

		void create(std::string filePath);
		void sortDirectory();
		void searchDirectory(char* name);
		//recursive helper for binary search
		void searchDirectory(char* name, int low, int high);
		
		void deleteEntry(char* name);
		void insertEntry(char* name, char* phone_number);
		
		// Merge sort and its helper. 
		std::vector<string> merge(std::vector<std::string> arr1, std::vector<std::string> arr2);
		std::vector<std::string> merge_sort(std::vector<std::string> arr0);
		
		// Randomized Quick sort and its helper
		int quick_sort(std::vector<int> &arr, int low, int high);
		int partition(std::vector<std::int> &arr, int low, int high);

		// Filters the sorted array. 
		int correct_them(std::vector<int> &args);

	private:
		std::vector<Entry*> entries;
};

#endif