#include <iostream>
#include <vector>
#include "vector.hpp"

int main()
{
	ft::vector<int> v(3, 5);
	ft::vector<int> v2(v);
	ft::vector<int> v3;

	int arr[] = {1, 2};
	ft::vector<int>::iterator it(&arr[0]);
	ft::vector<int>::iterator it2(&arr[1]);
	std::cout << "it == it2 -> " << (it == it2) << std::endl;
	std::cout << "it != it2 -> " << (it != it2) << std::endl;
	std::cout << "it < it2 -> " << (it < it2) << std::endl;
	std::cout << "it >= it2 ->" << (it >= it2) << std::endl;
	std::cout << "*it -> " << *it << std::endl;
	*it = 4;
	std::cout << "*it = 4... *it -> " << *it << std::endl;
	*it++;
	std::cout << "*it++... *it -> " << *it << std::endl;
	*it--;
	std::cout << "*it--... *it -> " << *it << std::endl;
	(*it)--;
	std::cout << "(*it)--... *it -> " << *it << std::endl;
	*it++ = 6;
	std::cout << "*it++ = 6... *it -> " << *it << std::endl;
	it--;
	std::cout << "it--... *it -> " << *it << std::endl;
	std::cout << "it[1] -> " << it[1] << std::endl;

	std::cout << "*(it + 1) -> " << *(it + 1) << std::endl;
	it2 = it + 1;
	std::cout << "it2 - it -> " << it2 - it << std::endl;

	//ft::vector<int>::const_iterator it3(it);
	ft::vector<int>::const_iterator it3;
	it3 = it;
	std::cout << "*it -> " << *it << std::endl;
	std::cout << "*it3 -> " << *it3 << std::endl;
	//*it3 = 8;
	std::cout << "it3[1] -> " << it3[1] << std::endl;
	std::cout << "it == it3 -> " << (it3 == it) << std::endl;
	std::cout << "it != it3 -> " << (it != it3) << std::endl;
	std::cout << "it < it3 -> " << (it < it3) << std::endl;
	std::cout << "it >= it3 ->" << (it >= it3) << std::endl;
	std::cout << "*(it3 + 1) -> " << *(it3 + 1) << std::endl;
	it3 = it + 1;
	std::cout << "it3 - it -> " << it3 - it << std::endl;
	it3 -= 1;
	std::cout << "it3 - it -> " << it3 - it << std::endl;
	it3 += 5;
	std::cout << "oit3[1] -> " << it3[-5] << std::endl;	

	std::cout << "\n____ORIGINALES____\n" << std::endl;

	std::vector<int> ov(3, 5);
	std::vector<int> ov2(ov);
	std::vector<int> ov3;
	ov3.push_back(9);
	ov3.push_back(10);
	ov3.push_back(11);
	std::vector<int>::iterator oit = ov3.begin();
	std::cout << oit[2] << std::endl;
	std::cout << *(oit+2) << std::endl;
	*oit++ = 6;
	std::cout << *oit << std::endl;
	oit--;
	std::cout << *oit << std::endl;
	std::vector<int>::iterator oit2 = oit + 1;
	std::cout << *oit2 << std::endl;
	std::cout << oit2 - oit << std::endl;

	std::vector<int>::const_iterator oit3;
	oit3 = oit;
	std::cout << "*oit -> " << *oit << std::endl;
	std::cout << "*oit3 -> " << *oit3 << std::endl;
	//*oit3 = 8;
	//std::cout << "*oit3 -> " << *oit3 << std::endl;
	std::cout << "oit3[1] -> " << oit3[1] << std::endl;	
	std::cout << "oit == oit3 -> " << (oit == oit3) << std::endl;
	std::cout  << *oit3 << std::endl;	
	
	oit3 += 5;
	std::cout  << *oit3 << std::endl;	
	std::cout << "oit3[1] -> " << oit3[1] << std::endl;
	std::cout  << *(oit3 +5) << std::endl;	
	std::cout << "oit3 == oit + 5 -> " << (*oit3 == *(oit3 + 5)) << std::endl;	
/*
	std::cout << v.capacity() << std::endl;
	v.reserve(2);
	std::cout << v.capacity() << std::endl;
	v.reserve(6);
	std::cout << v.capacity() << std::endl;
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
