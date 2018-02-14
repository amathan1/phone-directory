#include<vector>
#include<string>

#include "Entry.hpp"

#ifndef _PHONEDIRECTORY_HPP_

#define _PHONEDIRECTORY_HPP_

class PhoneDirectory{
	struct Pair;
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
		std::vector<Pair*> merge_sort(std::vector<Pair*> &arr0);
		std::vector<Pair*> merge(std::vector<Pair*> &arr1, std::vector<Pair*> &arr2);
		
		// Randomized Quick sort and its helper
		int quick_sort(std::vector<long> &arr, int low, int high, std::vector<int> &args);
		int partition(std::vector<long> &arr, int low, int high, std::vector<int> &args);

		// Filters the sorted array. 
		int correct_them(std::vector<int> &args);
		int correctHelper(std::vector< std::vector<int> > &same, std::vector< std::vector<std::string> > &same_str);
	private:
		std::vector<Entry*> entries;
};

#endif
