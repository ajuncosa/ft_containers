#include <iostream>
#include <vector>
#include "vector.hpp"
#include <stdexcept>

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

/*	std::cout << "\n-----BOOL SWAP-----" << std::endl;
	std::vector<bool> foo;
  	std::vector<bool> bar;
	foo.push_back(false);
	foo.push_back(true);
	foo.push_back(false);
	bar.push_back(true);
	bar.push_back(false);
	foo.swap(foo[0], foo[1]);
	bar.swap(bar.front(), bar.back());
	foo.swap(bar);
	std::cout << "foo vector contains:";
  	for (std::vector<bool>::iterator it = foo.begin() ; it != foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "bar vector contains:";
  	for (std::vector<bool>::iterator it = bar.begin() ; it != bar.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	ft::vector<bool> myfoo;
  	ft::vector<bool> mybar;
	myfoo.push_back(false);
	myfoo.push_back(true);
	myfoo.push_back(false);
	mybar.push_back(true);
	mybar.push_back(false);
	myfoo.swap(myfoo[0], myfoo[1]);
	mybar.swap(mybar.front(), mybar.back());
	myfoo.swap(mybar);
	std::cout << "myfoo vector contains:";
  	for (ft::vector<bool>::iterator it = myfoo.begin() ; it != myfoo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "mybar vector contains:";
  	for (ft::vector<bool>::iterator it = mybar.begin() ; it != mybar.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';*/

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
