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
		std::vector<std::string> merge(std::vector<std::string> &arr1, std::vector<std::string> &arr2, std::vector<int> &arg1, std::vector<int> &arg2, std::vector<int> &arg);
		std::vector<std::string> merge_sort(std::vector<std::string> &arr0, std::vector<int> &args);
		
		// Randomized Quick sort and its helper
		int quick_sort(std::vector<int> &arr, int low, int high, std::vector<int> &args);
		int partition(std::vector<int> &arr, int low, int high, std::vector<int> &args);

		// Filters the sorted array. 
		int correct_them(std::vector<int> &args);
		int correctHelper(std::vector< std::vector<int> > same, std::vector< std::vector<std::string> > same_str);
	private:
		std::vector<Entry*> entries;
};

#endif