#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>
#include "PhoneDirectory.hpp"

struct PhoneDirectory::Pair{
	std::string last_name;
	int idx;
};

PhoneDirectory::PhoneDirectory(std::string filePath){
	create(filePath);
}

PhoneDirectory::~PhoneDirectory(){
	int entryNum = this->entries.size();
	for(int i = 0; i < entryNum; i++) delete this->entries[i];
}


void PhoneDirectory::create(std::string filePath){
	std::ifstream in;
	in.open(filePath.c_str());
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
		this->entries.push_back(new Entry(firstName, lastName, pNum.substr(1, pNum.length())));
		//std::cout << "name: " << lastName << "\nnumber: " << pNum << std::endl;
		std::getline(in, token);
	}	
}

void 
PhoneDirectory::sortDirectory()
{

	// Sort people with lastname as the key
	std::vector<PhoneDirectory::Pair*> last_names;
	std::vector<int> args;

	for (int i = 0; i < this->entries.size(); i++)
	{
		last_names.push_back(new PhoneDirectory::Pair{this->entries[i]->getLastName(), i});
	}

	
	last_names = merge_sort(last_names);
	for(int i = 0; i < last_names.size(); i++) std::cout << last_names[i] << std::endl;
	std::vector<Entry*> new_entries;

	correct_them(args);

	for (int i = 0; i < args.size(); i++){
		new_entries.push_back(this->entries[args[i]]);
	}
	
	for(int i= 0; i < new_entries.size(); i++){
		entries[i] = new_entries[i];
	}
	
	new_entries.clear();

	return;

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
	for(int i = 0; i < this->entries.size(); i++){
		if(std::string(name).compare(entries[i]->getFirstName() +  " " + entries[i]->getLastName()) == 0) 
			entries.erase(entries.begin() + i--);
	}
}

void PhoneDirectory::insertEntry(char* name, char* phone_number){
	std::stringstream strStream;
	strStream << std::string(name);
	std::string firstName;
	std::string lastName;
	getline(strStream, firstName, ' ');
	getline(strStream, lastName);
	this->entries.push_back(new Entry(firstName, lastName, std::string(phone_number)));
}


std::vector<PhoneDirectory::Pair*> 
PhoneDirectory::merge(std::vector<PhoneDirectory::Pair*> &arr1, std::vector<PhoneDirectory::Pair*> &arr2)
{
	/* Recursive helper function */
	std::vector<PhoneDirectory::Pair*> arr;

	int c_i = arr1.size();
	int c_j = arr2.size();
	int i = 0, j = 0;

	while ((i < c_i) || (j < c_j))
	{
		if (i == c_i)
		{
			arr.push_back(arr2[j]);
			j++;
		}
		else if (j == c_j)
		{
			arr.push_back(arr1[i]);
			i++;
		}
		else if (arr1[i]->last_name.compare(arr2[j]->last_name) < 0)
		{
			arr.push_back(arr1[i]);
			i++;
		}
		else
		{
			arr.push_back(arr2[j]);
			j++;
		}
	}
	return arr;
}


std::vector<PhoneDirectory::Pair*> 
PhoneDirectory::merge_sort(std::vector<PhoneDirectory::Pair*> &arr0)
{	
	/*Mergesort: Takes a vector of string as input(Pass by value)
	 Returns sorted vector of strings */

	int size = arr0.size();
	
	if (size < 2)	return arr0;

	int med = size / 2;
	std::vector<PhoneDirectory::Pair*> arr1, arr2, out;

	for(int i = 0; i < size; ++i)
	{
		(i < med)?arr1.push_back(arr0[i]):arr2.push_back(arr0[i]);
	}

	arr1 = merge_sort(arr1);
	arr2 = merge_sort(arr2);
	out = merge(arr1, arr2);

	return out;
}



int 
PhoneDirectory::partition(std::vector<long> &arr, int low, int high, std::vector<int> &args)
{
	/* Helper for quicksort */
	int pivot, i, j, temp, temp2;
	i = low - 1;
	pivot = rand() % high;

	while (pivot < low)
		pivot = rand() % high;

	// For the elements
	temp = arr[pivot];
	arr[pivot] = arr[high - 1];
	arr[high-1] = temp;
	// For indices
	temp2 = args[pivot];
	args[pivot] = args[high-1];
	args[high-1] = temp2;
	
	pivot = high -1;


	for (j = low; j < high - 1; ++j)
	{
		if (arr[j] < arr[pivot]){
			i++;
			
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

			temp2 = args[i];
			args[i] = args[j];
			args[i] = args[j];
		}
	}

	i++;
	// Move pivot back to its place
	temp = arr[i];
	arr[i] = arr[pivot];
	arr[pivot] = temp;
	//For indices
	temp2 = args[i];
	args[i] = args[pivot];
	args[pivot] = temp2;

	return i;
}



int 
PhoneDirectory::quick_sort(std::vector<long> &arr, int low, int high, std::vector<int> &args)
{
	/* Quicksort: Pass by reference vector of integers and by value 0 and vector.size() */

	int pivot;
	if (high - low < 2)	return 0;

	pivot = partition(arr, low, high, args);

	quick_sort(arr, low, pivot, args);
	quick_sort(arr, pivot, high, args);

	return 0;
}



int 
PhoneDirectory::correctHelper(std::vector< std::vector<int> > same, std::vector< std::vector<std::string> > same_str)
{

	std::vector <int> args1; 
	int cur_i = 0;
	int cur_j = 0;

	for (int i = 0; i < same.size(); i++)
	{
		args1.clear();
		std::string temp_s = this->entries[same[i][0]]->getFirstName();
		bool hot = false;
		int start, end;

		for (int j = 0; j < same[i].size(); j++)
		{
			if (this->entries[same[i][j]]->getFirstName() == temp_s)
			{
					hot = true;
					args1.push_back(same[i][j]-1);
					start = j - 1;
			}

			else
			{
				if (hot == true)
				{
					end = j;
					args1.push_back(same[i][j]-1);
					hot = false;
				}
				temp_s = this->entries[same[i][j]]->getFirstName();
			}
		}
		
		int sz = (int)args1.size();
		
		if (sz > 0)
		{
			std::vector<long> phNos;
			for (int k = 0; k < sz; k++)
				phNos.push_back(this->entries[args1[k]]->getPhoneNum());
			
			quick_sort(phNos, 0, sz, args1);

			for (int k = 0; k < sz; k++)
				same[i][start+k] = args1[k];
		}
	}
	return 0;
}



int
PhoneDirectory::correct_them(std::vector<int> &args)
{
	std::string temp_s;
	std::vector <int> points;
	std::vector< std::vector<int> > same;
	std::vector< std::vector<std::string> > same_str;
	int cur_idx = 0;
	bool hot = false;
	int start;

	temp_s = this->entries[args[0]]->getLastName();

	{	// Finds same first names
		for (int i = 0; i < args.size(); i++)
		{
			if (this->entries[i]->getLastName() == temp_s)
			{
				if (same.size()==cur_idx)
					same.resize(same.size() + 1);
				
				same[cur_idx].push_back(args[i]-1);

				if (hot==false)
					start = i;
				
				hot = true;
				
			}

			else
			{
				if (hot == true)
				{
					same[cur_idx].push_back(args[i]-1);
					points.push_back(start);
					hot = false;
					cur_idx++;
				}
				temp_s = this->entries[args[i]]->getLastName();
			}
		}
	}

	same_str.resize(same.size());

	std::vector< std::vector<PhoneDirectory::Pair*> > forCorrection;

	for (int i = 0; i < same.size(); i++)
	{
		for (int j = 0; j < same[i].size(); j++)
		{
			// same_str[i].push_back(this->entries[j]->getFirstName());
			forCorrection[i].push_back(new PhoneDirectory::Pair{entries[same[i][j]]->getFirstName(), same[i][j]});
		}
	}

	for (int i = 0; i < forCorrection.size(); i++)
		forCorrection[i] = merge_sort(forCorrection[i]);

	for (int i = 0; i < forCorrection.size(); i++)
	{
		for (int j = 0; j < forCorrection[i].size(); j++)
		{
			same_str[i][j] = forCorrection[i][j]->last_name;
			same[i][j] = forCorrection[i][j]->idx;
		}
	}
	
	cur_idx = 0;
	int i = 0;

	correctHelper(same, same_str);

	while (i < args.size())
	{
		if (i==points[cur_idx])
		{
			for (int j = 0; j < same[cur_idx].size(); j++)
			{
				args[i] = same[cur_idx][j];
				i++;
			}
		}

		else
			i++;
	}
	return 0;
}
