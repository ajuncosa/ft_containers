#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <stdexcept>
#include "vector.hpp"
#include "stack.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"
#include "pair.hpp"
#include "map.hpp"

bool mycomp(int a, int b)
{
	return a < b;
}

int main()
{
	std::vector<int> std_v(3, 5);
	std::vector<int> std_v2(std_v);
	std::vector<int> std_v3;

	ft::vector<int> my_v(3, 5);
	ft::vector<int> my_v2(my_v);
	ft::vector<int> my_v3;

	std::cout << "-----STD VECTOR CONSTRUCTORS-----" << std::endl;
	std::cout << "standard vector contains:";
  	for (std::vector<int>::iterator it = std_v.begin() ; it != std_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	std::vector<int> std_v4(std_v.begin(), std_v.end() - 1); 
	std::cout << "std_v4 contains:";
  	for (std::vector<int>::iterator it = std_v4.begin() ; it != std_v4.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	std::cout << "\n-----MY VECTOR CONSTRUCTORS-----" << std::endl;
	std::cout << "my vector contains:";
  	for (ft::vector<int>::iterator it = my_v.begin() ; it != my_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	ft::vector<int> my_v4(my_v.begin(), my_v.end() - 1); 
	std::cout << "my_v4 contains:";
  	for (ft::vector<int>::iterator it = my_v4.begin() ; it != my_v4.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	std::cout << "\n-----SIZE AND CAPACITY-----" << std::endl;
	std::cout << "std size: " << std_v.size() << ", std cap: " <<std_v.capacity() <<std::endl;
	std::cout << "my_v size: " << my_v.size() << ", my_v cap: " <<my_v.capacity() <<std::endl;
	
	std::cout << "\n-----TRY TO RESIZE WITH MAX_SIZE-----" << std::endl;
	try
	{
		std_v.resize(std_v.max_size());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "std size: " << std_v.size() << ", std cap: " <<std_v.capacity() <<std::endl;
	std::cout << "standard vector contains:";
  	for (std::vector<int>::iterator it = std_v.begin() ; it != std_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	try
	{
		my_v.resize(std_v.max_size());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "my size: " << my_v.size() << ", my cap: " <<my_v.capacity() <<std::endl;
	std::cout << "my vector contains:";
  	for (ft::vector<int>::iterator it = my_v.begin() ; it != my_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	std::cout << "\n-----RESIZE TO 8-----" << std::endl;
	std_v.resize(8);
	std::cout << "std size: " << std_v.size() << ", std cap: " <<std_v.capacity() <<std::endl;
	std::cout << "standard vector contains:";
  	for (std::vector<int>::iterator it = std_v.begin() ; it != std_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	my_v.resize(8);
	std::cout << "my size: " << my_v.size() << ", my cap: " <<my_v.capacity() <<std::endl;
	std::cout << "my vector contains:";
  	for (ft::vector<int>::iterator it = my_v.begin() ; it != my_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	
	std::cout << "\n-----TRY TO RESIZE TO -1 (LENGTH ERROR)-----" << std::endl;
	try
	{std_v.resize(-1);}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "std size: " << std_v.size() << ", std cap: " <<std_v.capacity() <<std::endl;
	std::cout << "standard vector contains:";
  	for (std::vector<int>::iterator it = std_v.begin() ; it != std_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	try
	{my_v.resize(-1);}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "my size: " << my_v.size() << ", my cap: " <<my_v.capacity() <<std::endl;
	std::cout << "my vector contains:";
  	for (ft::vector<int>::iterator it = my_v.begin() ; it != my_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	std::cout << "\n-----RESIZE TO 4-----" << std::endl;
	std_v.resize(4);
	std::cout << "std size: " << std_v.size() << ", std cap: " <<std_v.capacity() <<std::endl;
	std::cout << "standard vector contains:";
  	for (std::vector<int>::iterator it = std_v.begin() ; it != std_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	my_v.resize(4);
	std::cout << "my size: " << my_v.size() << ", my cap: " <<my_v.capacity() <<std::endl;
	std::cout << "my vector contains:";
  	for (ft::vector<int>::iterator it = my_v.begin() ; it != my_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	std::cout << "\n-----ASSIGN-----" << std::endl;
	int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	std_v.assign(arr, arr+9);
	std::cout << "std size: " << std_v.size() << ", std cap: " <<std_v.capacity() <<std::endl;
	std::cout << "standard vector contains:";
  	for (std::vector<int>::iterator it = std_v.begin() ; it != std_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	my_v.assign(arr, arr+9);
	std::cout << "my size: " << my_v.size() << ", my cap: " <<my_v.capacity() <<std::endl;
	std::cout << "my vector contains:";
  	for (ft::vector<int>::iterator it = my_v.begin() ; it != my_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	std_v.assign(4, 5);
	std::cout << "std size: " << std_v.size() << ", std cap: " <<std_v.capacity() <<std::endl;
	std::cout << "standard vector contains:";
  	for (std::vector<int>::iterator it = std_v.begin() ; it != std_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	my_v.assign(4, 5);
	std::cout << "my size: " << my_v.size() << ", my cap: " <<my_v.capacity() <<std::endl;
	std::cout << "standard vector contains:";
  	for (ft::vector<int>::iterator it = my_v.begin() ; it != my_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	
	std::cout << "\n-----PUSH_BACK-----" << std::endl;
	std_v.push_back(10);
	std::cout << "std size: " << std_v.size() << ", std cap: " <<std_v.capacity() <<std::endl;
	std::cout << "standard vector contains:";
  	for (std::vector<int>::iterator it = std_v.begin() ; it != std_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	my_v.push_back(10);
	std::cout << "my size: " << my_v.size() << ", my cap: " <<my_v.capacity() <<std::endl;
	std::cout << "my vector contains:";
  	for (ft::vector<int>::iterator it = my_v.begin() ; it != my_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << "\n-----RESIZE TO CAPACITY + PUSH_BACK-----" << std::endl;
	std_v.resize(9,11);
	my_v.resize(9,11);
	std_v.push_back(15);
	std::cout << "std size: " << std_v.size() << ", std cap: " <<std_v.capacity() <<std::endl;
	std::cout << "standard vector contains:";
  	for (std::vector<int>::iterator it = std_v.begin() ; it != std_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	my_v.push_back(15);
	std::cout << "my size: " << my_v.size() << ", my cap: " <<my_v.capacity() <<std::endl;
	std::cout << "my vector contains:";
  	for (ft::vector<int>::iterator it = my_v.begin() ; it != my_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	std::cout << "\n-----POP_BACK-----" << std::endl;
	std_v.pop_back();
	std::cout << "std size: " << std_v.size() << ", std cap: " <<std_v.capacity() <<std::endl;
	std::cout << "standard vector contains:";
  	for (std::vector<int>::iterator it = std_v.begin() ; it != std_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	my_v.pop_back();
	std::cout << "my size: " << my_v.size() << ", my cap: " <<my_v.capacity() <<std::endl;
	std::cout << "my vector contains:";
  	for (ft::vector<int>::iterator it = my_v.begin() ; it != my_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	std::cout << "\n-----INSERT SINGLE VALUE-----" << std::endl;	
	std_v.insert(std_v.begin() + 2, 97);
	std::cout << "std size: " << std_v.size() << ", std cap: " <<std_v.capacity() <<std::endl;
	std::cout << "standard vector contains:";
  	for (std::vector<int>::iterator it = std_v.begin() ; it != std_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	my_v.insert(my_v.begin() + 2, 97);
	std::cout << "my size: " << my_v.size() << ", my cap: " <<my_v.capacity() <<std::endl;
	std::cout << "my vector contains:";
  	for (ft::vector<int>::iterator it = my_v.begin() ; it != my_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	
	std_v.insert(std_v.end(), 50);
	std::cout << "std size: " << std_v.size() << ", std cap: " <<std_v.capacity() <<std::endl;
	std::cout << "standard vector contains:";
  	for (std::vector<int>::iterator it = std_v.begin() ; it != std_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	my_v.insert(my_v.end(), 50);
	std::cout << "my size: " << my_v.size() << ", my cap: " <<my_v.capacity() <<std::endl;
	std::cout << "my vector contains:";
  	for (ft::vector<int>::iterator it = my_v.begin() ; it != my_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	std::cout << "\n-----INSERT SEVERAL VALUES-----" << std::endl;
	std_v.insert(std_v.begin() + 3, 5, 1);
	std::cout << "std size: " << std_v.size() << ", std cap: " <<std_v.capacity() <<std::endl;
	std::cout << "standard vector contains:";
  	for (std::vector<int>::iterator it = std_v.begin() ; it != std_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	my_v.insert(my_v.begin() + 3, 5, 1);
	std::cout << "my size: " << my_v.size() << ", my cap: " <<my_v.capacity() <<std::endl;
	std::cout << "my vector contains:";
  	for (ft::vector<int>::iterator it = my_v.begin() ; it != my_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	std::cout << "\n-----INSERT ITERATOR RANGE-----" << std::endl;
	std_v.insert(std_v.end() - 1, arr+6, arr+9);
	std::cout << "std size: " << std_v.size() << ", std cap: " <<std_v.capacity() <<std::endl;
	std::cout << "standard vector contains:";
  	for (std::vector<int>::iterator it = std_v.begin() ; it != std_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	my_v.insert(my_v.end() - 1, arr+6, arr+9);
	std::cout << "my size: " << my_v.size() << ", my cap: " <<my_v.capacity() <<std::endl;
	std::cout << "my vector contains:";
  	for (ft::vector<int>::iterator it = my_v.begin() ; it != my_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	std::cout << "\n-----ERASE SINGLE VALUE-----" << std::endl;
	std::vector<int>::iterator ret = std_v.erase(std_v.begin() + 1);
	std::cout << "std erase ret: " << *ret << std::endl;
	std::cout << "std size: " << std_v.size() << ", std cap: " <<std_v.capacity() <<std::endl;
	std::cout << "standard vector contains:";
  	for (std::vector<int>::iterator it = std_v.begin() ; it != std_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	ft::vector<int>::iterator myret = my_v.erase(my_v.begin() + 1);
	std::cout << "ft erase ret: " << *myret << std::endl;
	std::cout << "my size: " << my_v.size() << ", my cap: " <<my_v.capacity() <<std::endl;
	std::cout << "my vector contains:";
  	for (ft::vector<int>::iterator it = my_v.begin() ; it != my_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	std::cout << "\n-----ERASE RANGE-----" << std::endl;
	ret = std_v.erase(std_v.begin() + 3, std_v.end());
	if (ret == std_v.end())
		std::cout << "ret es end()" <<std::endl;
	std::cout << "std erase ret: " << *ret << std::endl;
	std::cout << "std size: " << std_v.size() << ", std cap: " <<std_v.capacity() <<std::endl;
	std::cout << "standard vector contains:";
  	for (std::vector<int>::iterator it = std_v.begin() ; it != std_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	myret = my_v.erase(my_v.begin() + 3, my_v.end());
	if (myret == my_v.end())
		std::cout << "myret es end()" <<std::endl;
	std::cout << "ft erase ret: " << *myret << std::endl;
	std::cout << "my size: " << my_v.size() << ", my cap: " <<my_v.capacity() <<std::endl;
	std::cout << "my vector contains:";
  	for (ft::vector<int>::iterator it = my_v.begin() ; it != my_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	
	std::cout << "\n-----SWAP-----" << std::endl;
	std_v.swap(std_v4);
	std::cout << "std size: " << std_v.size() << ", std cap: " <<std_v.capacity() <<std::endl;
	std::cout << "standard vector contains:";
  	for (std::vector<int>::iterator it = std_v.begin() ; it != std_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << "v4 size: " << std_v4.size() << ", v4 cap: " <<std_v4.capacity() <<std::endl;
	std::cout << "standard vector v4 contains:";
  	for (std::vector<int>::iterator it = std_v4.begin() ; it != std_v4.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	my_v.swap(my_v4);
	std::cout << "my size: " << my_v.size() << ", my cap: " <<my_v.capacity() <<std::endl;
	std::cout << "my vector contains:";
  	for (ft::vector<int>::iterator it = my_v.begin() ; it != my_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << "my v4 size: " << my_v4.size() << ", my v4 cap: " <<my_v4.capacity() <<std::endl;
	std::cout << "my vector v4 contains:";
  	for (ft::vector<int>::iterator it = my_v4.begin() ; it != my_v4.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	std::cout << "\n-----CLEAR-----" << std::endl;
	std_v4.clear();
	std::cout << "v4 size: " << std_v4.size() << ", v4 cap: " <<std_v4.capacity() <<std::endl;
	std::cout << "standard vector v4 contains:";
  	for (std::vector<int>::iterator it = std_v4.begin() ; it != std_v4.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	my_v4.clear();
	std::cout << "my v4 size: " << my_v4.size() << ", my v4 cap: " <<my_v4.capacity() <<std::endl;
	std::cout << "my vector v4 contains:";
  	for (ft::vector<int>::iterator it = my_v4.begin() ; it != my_v4.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	std::cout << "\n-----SWAP (non-member overload)-----" << std::endl;
	swap(std_v4, std_v);
	std::cout << "std size: " << std_v.size() << ", std cap: " <<std_v.capacity() <<std::endl;
	std::cout << "standard vector contains:";
  	for (std::vector<int>::iterator it = std_v.begin() ; it != std_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << "v4 size: " << std_v4.size() << ", v4 cap: " <<std_v4.capacity() <<std::endl;
	std::cout << "standard vector v4 contains:";
  	for (std::vector<int>::iterator it = std_v4.begin() ; it != std_v4.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	swap(my_v4, my_v);
	std::cout << "my size: " << my_v.size() << ", my cap: " <<my_v.capacity() <<std::endl;
	std::cout << "my vector contains:";
  	for (ft::vector<int>::iterator it = my_v.begin() ; it != my_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << "my v4 size: " << my_v4.size() << ", my v4 cap: " <<my_v4.capacity() <<std::endl;
	std::cout << "my vector v4 contains:";
  	for (ft::vector<int>::iterator it = my_v4.begin() ; it != my_v4.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	
	std::cout << "\n-----RELATIONAL OPERATORS-----" << std::endl;
	std::cout << "std_v == std_v4? " << (std_v == std_v4) << std::endl;
	std::cout << "my_v == my_v4? " << (my_v == my_v4) << std::endl;
	std::cout << "std_v == std::vector()? " << (std_v == std::vector<int>()) << std::endl;
	std::cout << "my_v == ft::vector()? " << (my_v == ft::vector<int>()) << std::endl;
	std_v.push_back(5);
	std_v.push_back(0);
	my_v.push_back(5);
	my_v.push_back(0);
	std::cout << "std_v == std_v4? " << (std_v == std_v4) << std::endl;
	std::cout << "my_v == my_v4? " << (my_v == my_v4) << std::endl;
	std::cout << "std_v != std_v4? " << (std_v != std_v4) << std::endl;
	std::cout << "my_v != my_v4? " << (my_v != my_v4) << std::endl;
	std::cout << "std_v < std_v4? " << (std_v < std_v4) << std::endl;
	std::cout << "my_v < my_v4? " << (my_v < my_v4) << std::endl;
	std::cout << "std_v <= std_v4? " << (std_v <= std_v4) << std::endl;
	std::cout << "my_v <= my_v4? " << (my_v <= my_v4) << std::endl;
	std::cout << "std_v > std_v4? " << (std_v > std_v4) << std::endl;
	std::cout << "my_v > my_v4? " << (my_v > my_v4) << std::endl;
	std::cout << "std_v >= std_v4? " << (std_v >= std_v4) << std::endl;
	std::cout << "my_v >= my_v4? " << (my_v >= my_v4) << std::endl;
	std::cout << "std size: " << std_v.size() << ", std cap: " <<std_v.capacity() <<std::endl;
	std::cout << "standard vector contains:";
  	for (std::vector<int>::iterator it = std_v.begin() ; it != std_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << "v4 size: " << std_v4.size() << ", v4 cap: " <<std_v4.capacity() <<std::endl;
	std::cout << "standard vector v4 contains:";
  	for (std::vector<int>::iterator it = std_v4.begin() ; it != std_v4.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << "my size: " << my_v.size() << ", my cap: " <<my_v.capacity() <<std::endl;
	std::cout << "my vector contains:";
  	for (ft::vector<int>::iterator it = my_v.begin() ; it != my_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << "my v4 size: " << my_v4.size() << ", my v4 cap: " <<my_v4.capacity() <<std::endl;
	std::cout << "my vector v4 contains:";
  	for (ft::vector<int>::iterator it = my_v4.begin() ; it != my_v4.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	std::cout << "\n-----EQUAL-----" << std::endl;
	std::cout << "std_v equal std_v4? " << std::equal(std_v.begin(), std_v.end(), std_v4.begin()) << std::endl;
	std::cout << "my_v equal my_v4? " << ft::equal(my_v.begin(),my_v.end(), my_v4.begin()) << std::endl;

	std::cout << "\n-----LEXICOGRAPHICAL_COMPARE-----" << std::endl;
	std::cout << "std_v < std_v4? " << std::lexicographical_compare(std_v.begin(), std_v.end(), std_v4.begin(), std_v4.end()) << std::endl;
	std::cout << "my_v < my_v4? " << ft::lexicographical_compare(my_v.begin(),my_v.end(), my_v4.begin(), my_v4.end()) << std::endl;
	std::cout << "std_v4 < std_v? " << std::lexicographical_compare(std_v4.begin(), std_v4.end(), std_v.begin(), std_v.end()) << std::endl;
	std::cout << "my_v4 < my_v? " << ft::lexicographical_compare(my_v4.begin(),my_v4.end(), my_v.begin(), my_v.end()) << std::endl;
	std::cout << "std_v < std_v4? (comp) " << std::lexicographical_compare(std_v.begin(), std_v.end(), std_v4.begin(), std_v4.end(), mycomp) << std::endl;
	std::cout << "my_v < my_v4? (comp) " << ft::lexicographical_compare(my_v.begin(),my_v.end(), my_v4.begin(), my_v4.end(), mycomp) << std::endl;
	std::cout << "std_v4 < std_v? (comp) " << std::lexicographical_compare(std_v4.begin(), std_v4.end(), std_v.begin(), std_v.end(), mycomp) << std::endl;
	std::cout << "my_v4 < my_v? (comp) " << ft::lexicographical_compare(my_v4.begin(),my_v4.end(), my_v.begin(), my_v.end(), mycomp) << std::endl;

	std::cout << "\n-----ELEMENT ACCESS-----" << std::endl;
	std::cout << "std_v[1]: " << std_v[1] << std::endl;
	std::cout << "my_v[1]: " << my_v[1] << std::endl;
	std::cout << "std_v.at(1): " << std_v.at(1) << std::endl;
	std::cout << "my_v.at(1): " << my_v.at(1) << std::endl;
	std::cout << "std_v.front(): " << std_v.front() << std::endl;
	std::cout << "my_v.front(): " << my_v.front() << std::endl;
	std::cout << "std_v.back(): " << std_v.back() << std::endl;
	std::cout << "my_v.back(): " << my_v.back() << std::endl;
	try
	{
		std::cout << "std_v.at(2): " << std_v.at(2) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "my_v.at(2): " << my_v.at(2) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-----REVERSE ITERATOR-----" << std::endl;
	std_v.push_back(10);
	std_v.push_back(15);
	std_v.push_back(20);
	std::cout << "standard vector contains:";
  	for (std::vector<int>::iterator it = std_v.begin() ; it != std_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << "standard vector contains (rev order):";
	for (std::vector<int>::reverse_iterator it = std_v.rbegin() ; it != std_v.rend(); ++it)
		std::cout << ' ' << *it;
  	std::cout << '\n';

	my_v.push_back(10);
	my_v.push_back(15);
	my_v.push_back(20);
	std::cout << "my vector contains:";
  	for (ft::vector<int>::iterator it = my_v.begin() ; it != my_v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << "my vector contains (rev order):";
	for (ft::vector<int>::reverse_iterator it = my_v.rbegin() ; it != my_v.rend(); ++it)
		std::cout << ' ' << *it;
  	std::cout << '\n';

	std::vector<int>::iterator it = std_v.end();
	std::vector<int>::reverse_iterator rev_it(it);
	std::vector<int>::reverse_iterator rev_it2(rev_it);
	std::cout << "*rev_it: " << *rev_it << std::endl;

	ft::vector<int>::iterator myit = my_v.end();
	ft::vector<int>::reverse_iterator myrev_it(myit);
	ft::vector<int>::reverse_iterator myrev_it2(myrev_it);
	std::cout << "*myrev_it: " << *myrev_it << std::endl;

	*rev_it = 19;
	std::cout << "*rev_it2: " << *rev_it2 << std::endl;

	*myrev_it = 19;
	std::cout << "*myrev_it2: " << *myrev_it2 << std::endl;

	rev_it2++;
	std::cout << "*rev_it: " << *rev_it << std::endl;

	myrev_it2++;
	std::cout << "*myrev_it: " << *myrev_it << std::endl;

	std::cout << "*rev_it2: " <<  *rev_it2 << std::endl;
	std::cout << "*myrev_it2: " << *myrev_it2 << std::endl;

	std::cout << "std vector contains (rev order, iterating from rev_it2): ";
	for (std::vector<int>::reverse_iterator it = rev_it2 ; it != std_v.rend(); ++it)
		std::cout << ' ' << *it;
  	std::cout << '\n';

	std::cout << "my vector contains (rev order, iterating from myrev_it2): ";
	for (ft::vector<int>::reverse_iterator it = myrev_it2 ; it != my_v.rend(); ++it)
		std::cout << ' ' << *it;
  	std::cout << '\n';

	std::vector<int>::const_reverse_iterator const_it = std_v.rbegin();
	ft::vector<int>::const_reverse_iterator my_const_it = my_v.rbegin();
	std::vector<int>::const_reverse_iterator std_crend = std_v.rend();
	ft::vector<int>::const_reverse_iterator my_crend = my_v.rend(); // necesario porque en c++98 el template de los comparadores solo admite un parametro, por lo que const y no-const no son comparables

	std::cout << "std vector contains (rev order, iterating with const_it): ";
	for (std::vector<int>::const_reverse_iterator it = const_it ; it != std_crend; ++it)
		std::cout << ' ' << *it;
  	std::cout << '\n';

	std::cout << "my vector contains (rev order, iterating with my_const_it): ";
	for (ft::vector<int>::const_reverse_iterator it = my_const_it ; it != my_crend; ++it)
		std::cout << ' ' << *it;
  	std::cout << '\n';

	std::cout << "*(rev_it + 2): " << *(rev_it + 2) << std::endl;
	std::cout << "*(myrev_it + 2): " << *(myrev_it + 2) << std::endl;
	std::cout << "*rev_it++: " << *rev_it++ << std::endl;
	std::cout << "*myrev_it++: " << *myrev_it++ << std::endl;
	std::cout << "*rev_it: " << *rev_it << std::endl;
	std::cout << "*myrev_it: " << *myrev_it << std::endl;
	std::cout << "*++rev_it: " << *++rev_it << std::endl;
	std::cout << "*++myrev_it: " << *++myrev_it << std::endl;
	std::cout << "*(rev_it - 2): " << *(rev_it - 2) << std::endl;
	std::cout << "*(myrev_it - 2): " << *(myrev_it - 2) << std::endl;
	std::cout << "*--rev_it: " << *--rev_it << std::endl;
	std::cout << "*--myrev_it: " << *--myrev_it << std::endl;
	std::cout << "*(rev_it -= 1): " << *(rev_it -= 1) << std::endl;
	std::cout << "*(myrev_it -= 1): " << *(myrev_it -= 1) << std::endl;
	std::cout << "rev_it[2]: " << rev_it[2] << std::endl;
	std::cout << "myrev_it[2]: " << myrev_it[2] << std::endl;
	std::cout << "*(4 + rev_it): " << *(4 + rev_it) << std::endl;
	std::cout << "*(4 + myrev_it): " << *(4 + myrev_it) << std::endl;
	std::cout << "rev_it - (rev_it2 + 3): " << rev_it - (rev_it2 + 3) << std::endl;
	std::cout << "myrev_it - (myrev_it2 + 3): " << myrev_it - (myrev_it2 + 3) << std::endl;
	std::cout << "(rev_it2 + 3) - rev_it: " << (rev_it2 + 3) - rev_it << std::endl;
	std::cout << "(myrev_it2 + 3) - myrev_it: " << (myrev_it2 + 3) - myrev_it << std::endl;
	std::cout << "rev_it == rev_it2? " << (rev_it == rev_it2) << std::endl;
	std::cout << "myrev_it == myrev_it2? " << (myrev_it == myrev_it2) << std::endl;
	std::cout << "rev_it <= rev_it2? " << (rev_it <= rev_it2) << std::endl;
	std::cout << "myrev_it <= myrev_it2? " << (myrev_it <= myrev_it2) << std::endl;
	std::cout << "rev_it >= rev_it2? " << (rev_it >= rev_it2) << std::endl;
	std::cout << "myrev_it >= myrev_it2? " << (myrev_it >= myrev_it2) << std::endl;
	std::cout << "rev_it2 > rev_it? " << (rev_it2 > rev_it) << std::endl;
	std::cout << "myrev_it2 > myrev_it? " << (myrev_it2 > myrev_it) << std::endl;

	std::cout << "\n-----STACK-----" << std::endl;
	std::stack<int, std::vector<int> > std_s;
	ft::stack<int, ft::vector<int> > ft_s;
	//std::cout << "std_s top" << std_s.top() << std::endl;
	//std::cout << "ft_s top" << ft_s.top() << std::endl;
	std::cout << "std_s empty: " << std_s.empty() << std::endl;
	std::cout << "ft_s empty: " << ft_s.empty() << std::endl;
	std::cout << "std_s size: " << std_s.size() << std::endl;
	std::cout << "ft_s size: " << ft_s.size() << std::endl;
	std::cout <<"pushing..." <<std::endl;
	std_s.push(2);
	ft_s.push(2);
	std::cout << "std_s empty: " << std_s.empty() << std::endl;
	std::cout << "ft_s empty: " << ft_s.empty() << std::endl;
	std::cout << "std_s top: " << std_s.top() << std::endl;
	std::cout << "ft_s top: " << ft_s.top() << std::endl;
	std::cout <<"pushing..." <<std::endl;
	std_s.push(4);
	ft_s.push(4);
	std::cout << "std_s top: " << std_s.top() << std::endl;
	std::cout << "ft_s top: " << ft_s.top() << std::endl;
	std::cout << "std_s size: " << std_s.size() << std::endl;
	std::cout << "ft_s size: " << ft_s.size() << std::endl;
	std::cout <<"popping..." <<std::endl;
	std_s.pop();
	ft_s.pop();
	std::cout << "std_s top: " << std_s.top() << std::endl;
	std::cout << "ft_s top: " << ft_s.top() << std::endl;
	std::cout << "std_s size: " << std_s.size() << std::endl;
	std::cout << "ft_s size: " << ft_s.size() << std::endl;
	std::stack<int, std::vector<int> > std_s1;
	std_s1.push(2);
	ft::stack<int> ft_s1;
	ft_s1.push(2);
	std::cout << "std_s == std_s1? " << (std_s == std_s1) << std::endl;
	std::cout << "ft_s == ft_s1? " << (ft_s == ft_s1) << std::endl;
	std::cout << "std_s != std_s1? " << (std_s != std_s1) << std::endl;
	std::cout << "ft_s != ft_s1? " << (ft_s != ft_s1) << std::endl;
	std::cout << "std_s < std_s1? " << (std_s < std_s1) << std::endl;
	std::cout << "ft_s < ft_s1? " << (ft_s < ft_s1) << std::endl;
	std::cout << "std_s <= std_s1? " << (std_s <= std_s1) << std::endl;
	std::cout << "ft_s <= ft_s1? " << (ft_s <= ft_s1) << std::endl;
	std::cout << "std_s > std_s1? " << (std_s > std_s1) << std::endl;
	std::cout << "ft_s > ft_s1? " << (ft_s > ft_s1) << std::endl;
	std::cout << "std_s >= std_s1? " << (std_s >= std_s1) << std::endl;
	std::cout << "ft_s >= ft_s1? " << (ft_s >= ft_s1) << std::endl;
	
	std::cout << "\n-----PAIR-----" << std::endl;
	std::pair<int,std::string> std_pair = std::make_pair(1, "hola");
	std::cout << "std_pair.first, std_pair.second: " << std_pair.first << ", " << std_pair.second <<std::endl;
	ft::pair<int,std::string> ft_pair = ft::make_pair(1, "hola");
	std::cout << "ft_pair.first, ft_pair.second: " << ft_pair.first << ", " << ft_pair.second <<std::endl;
	

	//ft::vector<int> const vect;
	//ft::vector<int>::const_iterator iter = vect.begin();
	//ft::vector<int>::iterator iter2(iter);

	std::cout << "\n-----MAP INSERT-----" << std::endl;
	std::map<int, std::string> std_map;
	std_map.insert(std_pair);
	std_map.insert(std::pair<int, std::string>(2, "que"));
	std_map.insert(std::pair<int, std::string>(4, "tal"));
	std_map.insert(std::pair<int, std::string>(3, "bien"));
    std::cout << "The map std_map is : \n";
    std::cout << "\tKEY\tELEMENT\n";
    for (std::map<int, std::string>::iterator itr = std_map.begin(); itr != std_map.end(); ++itr)
    	std::cout << '\t' << itr->first << '\t' << itr->second << std::endl;

	ft::map<int, std::string> ft_map;
	ft_map.insert(ft_pair);
	ft_map.insert(ft::pair<int, std::string>(2, "que"));
	ft_map.insert(ft::pair<int, std::string>(4, "tal"));
	ft_map.insert(ft::pair<int, std::string>(3, "bien"));
    std::cout << "The map ft_map is : \n";
    std::cout << "\tKEY\tELEMENT\n";
    for (ft::map<int, std::string>::iterator itr = ft_map.begin(); itr != ft_map.end(); ++itr)
    	std::cout << '\t' << itr->first << '\t' << itr->second << std::endl;


	std::cout << "\n-----MAP RANGE CONSTRUCTOR-----" << std::endl;
	std::pair<int, std::string> pair_arr[] = {std::make_pair(42, "a"), std::make_pair(43, "b"), std::make_pair(44, "c")};
	//std::map<int, std::string>::iterator sb = std_map.begin();
	//std::map<int, std::string>::iterator se = std_map.end();
	std::map<int, std::string> smap(&pair_arr[0], &pair_arr[3]);

	ft::pair<int, std::string> ftpair_arr[] = {ft::make_pair(42, "a"), ft::make_pair(43, "b"), ft::make_pair(44, "c")};
//	ft::map<int, std::string>::iterator ftb = ft_map.begin();
//	ft::map<int, std::string>::iterator fte = ftb++;//ft_map.end();
	ft::map<int, std::string> ftmap(&ftpair_arr[0], &ftpair_arr[3]);

	std::cout << "The map smap is : \n";
    std::cout << "\tKEY\tELEMENT\n";
    for (std::map<int, std::string>::iterator itr = smap.begin(); itr != smap.end(); ++itr)
    	std::cout << '\t' << itr->first << '\t' << itr->second << std::endl;
	std::cout << "The map ftmap is : \n";
    std::cout << "\tKEY\tELEMENT\n";
    for (ft::map<int, std::string>::iterator itr = ftmap.begin(); itr != ftmap.end(); ++itr)
    	std::cout << '\t' << itr->first << '\t' << itr->second << std::endl;
	
	std::cout << "\n-----MAP COPY CONSTRUCTOR-----" << std::endl;
	std::map<int, std::string> scopy(std_map);
	std::cout << "The map scopy is : \n";
	std::cout << "\tKEY\tELEMENT\n";
	for (std::map<int, std::string>::iterator itr = scopy.begin(); itr != scopy.end(); ++itr)
		std::cout << '\t' << itr->first << '\t' << itr->second << std::endl;		//ft::map<int, std::string> ftcopy(ft_map);
	
	ft::map<int, std::string> ftcopy(ft_map);
	std::cout << "The map ftcopy is : \n";
	std::cout << "\tKEY\tELEMENT\n";
	for (ft::map<int, std::string>::iterator itr = ftcopy.begin(); itr != ftcopy.end(); ++itr)
		std::cout << '\t' << itr->first << '\t' << itr->second << std::endl;

	std::cout << "\n-----MAP RANGE INSERT-----" << std::endl;
	std_map.insert(smap.begin(), smap.end());
//	std_map.insert(&pair_arr[0], &pair_arr[3]);
	std::cout << "The map std_map is : \n";
    std::cout << "\tKEY\tELEMENT\n";
    for (std::map<int, std::string>::iterator itr = std_map.begin(); itr != std_map.end(); ++itr)
    	std::cout << '\t' << itr->first << '\t' << itr->second << std::endl;

	ft_map.insert(ftmap.begin(), ftmap.end());
//	ft_map.insert(&ftpair_arr[0], &ftpair_arr[3]);
	std::cout << "The map ft_map is : \n";
	std::cout << "\tKEY\tELEMENT\n";
	for (ft::map<int, std::string>::iterator itr = ft_map.begin(); itr != ft_map.end(); ++itr)
		std::cout << '\t' << itr->first << '\t' << itr->second << std::endl;

	std::cout << "\n-----MAP HINT INSERT-----" << std::endl;
	std::map<int, std::string>::iterator sHint = std_map.find(42);
	std_map.insert(sHint, std::pair<int, std::string>(10, "hinting"));
	std::cout << "The map std_map is : \n";
    std::cout << "\tKEY\tELEMENT\n";
    for (std::map<int, std::string>::iterator itr = std_map.begin(); itr != std_map.end(); ++itr)
    	std::cout << '\t' << itr->first << '\t' << itr->second << std::endl;

	ft::map<int, std::string>::iterator ftHint = ft_map.find(4);
	ft_map.insert(ftHint, ft::pair<int, std::string>(10, "hinting"));
	std::cout << "The map ft_map is : \n";
	std::cout << "\tKEY\tELEMENT\n";
	for (ft::map<int, std::string>::iterator itr = ft_map.begin(); itr != ft_map.end(); ++itr)
		std::cout << '\t' << itr->first << '\t' << itr->second << std::endl;


	//std::cout << "std_map[2]: " << std_map[2] << std::endl;

	//std::cout << "std_map[2]: " << std_map[2] << std::endl;


	/*ft::map<int, std::string>::iterator itr;
    std::cout << "The map std_map is : \n";
    std::cout << "\tKEY\tELEMENT\n";
    for (itr = std_map.begin(); itr != std_map.end(); ++itr) {
    	std::cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
	std::cout << "std_map[2]: " << std_map[2] << std::endl;
*/

	return 0;
}

/*#include <iostream>
#include <string>
#include <deque>
#if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include <map.hpp>
	#include <stack.hpp>
	#include <vector.hpp>
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	return (0);
}*/
