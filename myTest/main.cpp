
#include <iostream>
#include <vector>
#include <stack>
#include <map>
//#include <stdexcept>
#include "../vector.hpp"
#include "../stack.hpp"
#include "../equal.hpp"
#include "../lexicographical_compare.hpp"
#include "../pair.hpp"
#include "../map.hpp"

#define TYPE1 int
#define TYPE2 std::string

bool mycomp(TYPE1 a, TYPE1 b)
{
	return a < b;
}

void printVector(NS::vector<TYPE1> v, std::string name)
{
	std::cout << name << " contains:";
	for (NS::vector<TYPE1>::iterator it = v.begin() ; it != v.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << name << " size: " << v.size() << std::endl;
}

void revPrintVector(NS::vector<TYPE1> v, std::string name)
{
	std::cout << name << " contains (rev order):";
	for (NS::vector<TYPE1>::reverse_iterator it = v.rbegin() ; it != v.rend(); ++it)
		std::cout << ' ' << *it;
  	std::cout << '\n';
}

void vectorTests()
{
	NS::vector<TYPE1> v(3,5);
	NS::vector<TYPE1> v2(v);
	NS::vector<TYPE1> v3;

	std::cout << "\033[1;33m  ==============================" << std::endl;
	std::cout << "||            VECTOR            ||" << std::endl;
	std::cout << "  ==============================\033[0m" << std::endl;

	std::cout << "-----VECTOR CONSTRUCTORS, SIZE AND CAPACITY-----" << std::endl;
	printVector(v, "v");
	NS::vector<TYPE1> v4(v.begin(), v.end() - 1); 
	printVector(v4, "v4");
	std::cout << ", cap: " << v.capacity() << std::endl;

	std::cout << "\n-----TRY TO RESIZE WITH MAX_SIZE-----" << std::endl;
	try
	{
		v.resize(v.max_size());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	printVector(v, "v");

	std::cout << "\n-----RESIZE TO 8-----" << std::endl;
	v.resize(8);
	printVector(v, "v");

	std::cout << "\n-----TRY TO RESIZE TO -1 (LENGTH ERROR)-----" << std::endl;
	try
	{
		v.resize(-1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	printVector(v, "v");

	std::cout << "\n-----RESIZE TO 4-----" << std::endl;
	v.resize(4);
	printVector(v, "v");

	std::cout << "\n-----ASSIGN-----" << std::endl;
	TYPE1 arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	v.assign(arr, arr+9);
	printVector(v, "v");
	v.assign(4, 5);
	printVector(v, "v");

	std::cout << "\n-----PUSH_BACK-----" << std::endl;
	v.push_back(10);
	printVector(v, "v");

	std::cout << "\n-----RESIZE TO CAPACITY + PUSH_BACK-----" << std::endl;
	v.resize(9,11);
	v.push_back(15);
	printVector(v, "v");

	std::cout << "\n-----POP_BACK-----" << std::endl;
	v.pop_back();
	printVector(v, "v");

	std::cout << "\n-----INSERT SINGLE VALUE-----" << std::endl;	
	v.insert(v.begin() + 2, 97);
	printVector(v, "v");
	v.insert(v.end(), 50);
	printVector(v, "v");

	std::cout << "\n-----INSERT SEVERAL VALUES-----" << std::endl;
	v.insert(v.begin() + 3, 5, 1);
	printVector(v, "v");

	std::cout << "\n-----INSERT ITERATOR RANGE-----" << std::endl;
	v.insert(v.end() - 1, arr+6, arr+9);
	printVector(v, "v");

	std::cout << "\n-----ERASE SINGLE VALUE-----" << std::endl;
	NS::vector<TYPE1>::iterator ret = v.erase(v.begin() + 1);
	std::cout << "erase ret: " << *ret << std::endl;
	printVector(v, "v");

	std::cout << "\n-----ERASE RANGE-----" << std::endl;
	ret = v.erase(v.begin() + 3, v.end());
	if (ret == v.end())
		std::cout << "ret es end()" <<std::endl;
	std::cout << "erase ret: " << *ret << std::endl;
	printVector(v, "v");

	std::cout << "\n-----SWAP-----" << std::endl;
	v.swap(v4);
	printVector(v, "v");
	printVector(v4, "v4");

	std::cout << "\n-----CLEAR-----" << std::endl;
	v4.clear();
	printVector(v4, "v4");

	std::cout << "\n-----SWAP (non-member overload)-----" << std::endl;
	swap(v4, v);
	printVector(v, "v");
	printVector(v4, "v4");

	std::cout << "\n-----RELATIONAL OPERATORS-----" << std::endl;
	std::cout << "v == v4? " << (v == v4) << std::endl;
	std::cout << "v == std::vector()? " << (v == NS::vector<TYPE1>()) << std::endl;
	v.push_back(5);
	v.push_back(0);
	std::cout << "v == v4? " << (v == v4) << std::endl;
	std::cout << "v != v4? " << (v != v4) << std::endl;
	std::cout << "v < v4? " << (v < v4) << std::endl;
	std::cout << "v <= v4? " << (v <= v4) << std::endl;
	std::cout << "v > v4? " << (v > v4) << std::endl;
	std::cout << "v >= v4? " << (v >= v4) << std::endl;
	printVector(v, "v");
	printVector(v4, "v4");

	// TODO: comprobar EQUAL y LEXICOGRAPHICAL con otros tipos de contenedores?
	std::cout << "\n-----EQUAL-----" << std::endl;
	std::cout << "v equal v4? " << NS::equal(v.begin(), v.end(), v4.begin()) << std::endl;

	std::cout << "\n-----LEXICOGRAPHICAL_COMPARE-----" << std::endl;
	std::cout << "v < v4? " << std::lexicographical_compare(v.begin(), v.end(), v4.begin(), v4.end()) << std::endl;
	std::cout << "v4 < v? " << std::lexicographical_compare(v4.begin(), v4.end(), v.begin(), v.end()) << std::endl;
	std::cout << "v < v4? (comp) " << std::lexicographical_compare(v.begin(), v.end(), v4.begin(), v4.end(), mycomp) << std::endl;
	std::cout << "v4 < v? (comp) " << std::lexicographical_compare(v4.begin(), v4.end(), v.begin(), v.end(), mycomp) << std::endl;

	std::cout << "\n-----ELEMENT ACCESS-----" << std::endl;
	std::cout << "v[1]: " << v[1] << std::endl;
	std::cout << "v.at(1): " << v.at(1) << std::endl;
	std::cout << "v.front(): " << v.front() << std::endl;
	std::cout << "v.back(): " << v.back() << std::endl;
	try
	{
		std::cout << "v.at(2): " << v.at(2) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-----REVERSE ITERATOR-----" << std::endl;
	v.push_back(10);
	v.push_back(15);
	v.push_back(20);
	printVector(v, "v");
	revPrintVector(v, "v");
	NS::vector<TYPE1>::iterator it = v.end();
	NS::vector<TYPE1>::reverse_iterator rev_it(it);
	NS::vector<TYPE1>::reverse_iterator rev_it2(rev_it);
	std::cout << "*rev_it: " << *rev_it << std::endl;
	*rev_it = 19;
	std::cout << "*rev_it2: " << *rev_it2 << std::endl;
	rev_it2++;
	std::cout << "*rev_it: " << *rev_it << std::endl;
	std::cout << "*rev_it2: " << *rev_it2 << std::endl;
	std::cout << "v contains (rev order, iterating from rev_it2): ";
	for (NS::vector<TYPE1>::reverse_iterator it = rev_it2; it != v.rend(); ++it)
		std::cout << ' ' << *it;
  	std::cout << '\n';
	NS::vector<TYPE1>::const_reverse_iterator const_it = v.rbegin();
	NS::vector<TYPE1>::const_reverse_iterator crend = v.rend(); // necesario porque en c++98 el template de los comparadores solo admite un parametro, por lo que const y no-const no son comparables
	std::cout << "v contains (rev order, iterating with const_it): ";
	for (NS::vector<TYPE1>::const_reverse_iterator it = const_it; it != crend; ++it)
		std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << "*(rev_it + 2): " << *(rev_it + 2) << std::endl;
	std::cout << "*rev_it++: " << *rev_it++ << std::endl;
	std::cout << "*rev_it: " << *rev_it << std::endl;
	std::cout << "*++rev_it: " << *++rev_it << std::endl;
	std::cout << "*(rev_it - 2): " << *(rev_it - 2) << std::endl;
	std::cout << "*--rev_it: " << *--rev_it << std::endl;
	std::cout << "*(rev_it -= 1): " << *(rev_it -= 1) << std::endl;
	std::cout << "rev_it[2]: " << rev_it[2] << std::endl;
	std::cout << "*(4 + rev_it): " << *(4 + rev_it) << std::endl;
	std::cout << "rev_it - (rev_it2 + 3): " << rev_it - (rev_it2 + 3) << std::endl;
	std::cout << "(rev_it2 + 3) - rev_it: " << (rev_it2 + 3) - rev_it << std::endl;
	std::cout << "rev_it == rev_it2? " << (rev_it == rev_it2) << std::endl;
	std::cout << "rev_it <= rev_it2? " << (rev_it <= rev_it2) << std::endl;
	std::cout << "rev_it >= rev_it2? " << (rev_it >= rev_it2) << std::endl;
	std::cout << "rev_it2 > rev_it? " << (rev_it2 > rev_it) << std::endl;

	std::cout << "\n-----CONST ITERATOR TESTS-----" << std::endl;
	std::cout << "should not compile" << std::endl;
	//NS::vector<TYPE1> const vect;
	//NS::vector<TYPE1>::const_iterator iter = vect.begin();
	//NS::vector<TYPE1>::iterator iter2(iter);

	std::cout << "\n\n";
}

void stackTests()
{
	std::cout << "\033[1;33m  ==============================" << std::endl;
	std::cout << "||            STACK             ||" << std::endl;
	std::cout << "  ==============================\033[0m" << std::endl;

	NS::stack<TYPE1, NS::vector<TYPE1> > s;
	//std::cout << "s top" << s.top() << std::endl; //std segfault
	std::cout << "s empty: " << s.empty() << std::endl;
	std::cout << "s size: " << s.size() << std::endl;
	std::cout <<"pushing..." <<std::endl;
	s.push(2);
	std::cout << "s empty: " << s.empty() << std::endl;
	std::cout << "s top: " << s.top() << std::endl;
	std::cout <<"pushing..." <<std::endl;
	s.push(4);
	std::cout << "s top: " << s.top() << std::endl;
	std::cout << "s size: " << s.size() << std::endl;
	std::cout <<"popping..." <<std::endl;
	s.pop();
	std::cout << "s top: " << s.top() << std::endl;
	std::cout << "s size: " << s.size() << std::endl;
	NS::stack<TYPE1, NS::vector<TYPE1> > s1;
	s1.push(2);
	std::cout << "s == s1? " << (s == s1) << std::endl;
	std::cout << "s != s1? " << (s != s1) << std::endl;
	std::cout << "s < s1? " << (s < s1) << std::endl;
	std::cout << "s <= s1? " << (s <= s1) << std::endl;
	std::cout << "s > s1? " << (s > s1) << std::endl;
	std::cout << "s >= s1? " << (s >= s1) << std::endl;
	std::cout << "\n\n";
}

void printMap(NS::map<TYPE1, TYPE2> map, std::string name)
{
    std::cout << name << " contains: \n";
    std::cout << "\tKEY\tELEMENT\n";
    for (NS::map<TYPE1, TYPE2>::iterator itr = map.begin(); itr != map.end(); ++itr)
    	std::cout << '\t' << itr->first << '\t' << itr->second << std::endl;
	std::cout << name << " size: " << map.size() << std::endl;

}

void mapTests()
{
	std::cout << "\033[1;33m  ==============================" << std::endl;
	std::cout << "||              MAP             ||" << std::endl;
	std::cout << "  ==============================\033[0m" << std::endl;

	std::cout << "\n-----PAIR-----" << std::endl;
	NS::pair<TYPE1,TYPE2> pair = NS::make_pair(1, "hola");
	std::cout << "pair.first, pair.second: " << pair.first << ", " << pair.second << std::endl;
	
	std::cout << "\n-----MAP INSERT-----" << std::endl;
	NS::map<TYPE1, TYPE2> m;
	m.insert(pair);
	m.insert(NS::pair<TYPE1, TYPE2>(2, "que"));
	m.insert(NS::pair<TYPE1, TYPE2>(4, "tal"));
	m.insert(NS::pair<TYPE1, TYPE2>(3, "bien"));
	printMap(m, "m");

	std::cout << "\n-----MAP RANGE CONSTRUCTOR-----" << std::endl;
	NS::map<TYPE1, TYPE2>::iterator it = m.begin();
	NS::map<TYPE1, TYPE2>::iterator ite = --(--m.end());
	NS::map<TYPE1, TYPE2> map(it, ite);
	printMap(map, "map");
	NS::pair<TYPE1, TYPE2> pair_arr[] = {NS::make_pair(42, "a"), NS::make_pair(43, "b"), NS::make_pair(44, "c")};
	NS::map<TYPE1, TYPE2> m2(&pair_arr[0], &pair_arr[3]);
	printMap(m2, "m2");

	std::cout << "\n-----MAP COPY CONSTRUCTOR-----" << std::endl;
	NS::map<TYPE1, TYPE2> copy(m);
	printMap(copy, "copy");

	std::cout << "\n-----MAP RANGE INSERT-----" << std::endl;
	m.insert(map.begin(), map.end());
	printMap(m, "m");
	m2.insert(&pair_arr[0], &pair_arr[3]);
	printMap(m2, "m2");

	std::cout << "\n-----MAP HINT INSERT-----" << std::endl;
	NS::map<TYPE1, TYPE2>::iterator hint = m.find(4);
	m.insert(hint, NS::pair<TYPE1, TYPE2>(10, "hinting"));
	printMap(m, "m");

	NS::map<TYPE1, TYPE2> emptyMap;
	std::cout << "emptyMap is empty? " << emptyMap.empty() << std::endl;
	emptyMap.insert(emptyMap.begin(), NS::pair<TYPE1, TYPE2>(10, "hinting"));
	emptyMap.insert(emptyMap.begin(), NS::pair<TYPE1, TYPE2>(15, "aaa"));
	emptyMap.insert(emptyMap.begin(), NS::pair<TYPE1, TYPE2>(5, "bbb"));
	emptyMap.insert(emptyMap.end(), NS::pair<TYPE1, TYPE2>(8, "ccc"));
	emptyMap.insert(emptyMap.find(10), NS::pair<TYPE1, TYPE2>(12, "ddd"));
	printMap(emptyMap, "emptyMap");
	
	std::cout << "\n-----COUNT-----" << std::endl;
	std::cout << "emptyMap count of key 12: " << emptyMap.count(12) << std::endl;
	std::cout << "emptyMap count of key 13: " << emptyMap.count(13) << std::endl;

	std::cout << "\n-----LOWER/UPPER_BOUND-----" << std::endl;
	std::cout << "m lower_bound of key 4: " << m.lower_bound(4)->first << ", " << m.lower_bound(4)->second << std::endl;
	std::cout << "m lower_bound of key 5: " << m.lower_bound(5)->first << ", " << m.lower_bound(5)->second << std::endl;
	std::cout << "m upper_bound of key 4: " << m.upper_bound(4)->first << ", " << m.upper_bound(4)->second << std::endl;
	std::cout << "m upper_bound of key 5: " << m.upper_bound(5)->first << ", " << m.upper_bound(5)->second << std::endl;
	
	std::cout << "\n-----EQUAL_RANGE-----" << std::endl;
	NS::pair<NS::map<TYPE1, TYPE2>::iterator, NS::map<TYPE1, TYPE2>::iterator> equal = m.equal_range(4);
	std::cout << "m equal_range of key 4: ";
	while (equal.first != equal.second)
	{
		std::cout << equal.first->first << ", " << equal.first->second << "; ";
		equal.first++;
	}
	std::cout << std::endl;

	std::cout << "\n-----VALUE_COMPARE-----" << std::endl;
	NS::map<TYPE1, TYPE2>::value_compare comp_func = m.value_comp();
	NS::pair<TYPE1, TYPE2> pair2 = NS::make_pair(6, "hola");
	std::cout << std::boolalpha << "comp_func(begin, pair2): " << comp_func(*m.begin(), pair2) << std::endl;
	std::cout << std::boolalpha << "comp_func(pair2, begin): " << comp_func(pair2, *m.begin()) << std::endl;

	std::cout << "\n-----ERASE-----" << std::endl;
	printMap(m, "m");
	std::cout << "erasing iterator begin" << std::endl;
	m.erase(m.begin());
	std::cout << "erasing key 10" << std::endl;
	m.erase(10);
	std::cout << "erasing by range, 42 to end" << std::endl;
	m.erase(m.find(42), m.end());
	printMap(m, "m");

	std::cout << "\n-----SWAP-----" << std::endl;
	m.swap(emptyMap);
	printMap(m, "m");
	printMap(emptyMap, "emptyMap");
	
	std::cout << "\n-----MAP NON-MEMBER SWAP-----" << std::endl;
	NS::swap(m, emptyMap);
	printMap(m, "m");
	printMap(emptyMap, "emptyMap");

	std::cout << "\n-----CLEAR-----" << std::endl;
	m.clear();
	printMap(m, "m");
	m.insert(NS::pair<TYPE1, TYPE2>(10, "hola"));
	m.insert(NS::pair<TYPE1, TYPE2>(5, "que"));
	m.insert(NS::pair<TYPE1, TYPE2>(42, "tal"));
	printMap(m, "m");

	std::cout << "\n-----ASSIGNMENT OPERATOR-----" << std::endl;
	m = emptyMap;
	printMap(m, "m");

	std::cout << "\n-----MAP OPERATOR[]-----" << std::endl;
	std::cout << "m[2]: " << m[2] << std::endl;
	std::cout << "m[42]: " << m[42] << std::endl;
	std::cout << "m[5]: " << m[5] << std::endl;
	std::cout << "m[15]: " << m[15] << std::endl;
	printMap(m, "m");
	m[42] = "bye";
	m[1] = "hello";
	std::cout << "m[42]: " << m[42] << std::endl;

	std::cout << "\n-----REVERSE ITERATOR-----" << std::endl;
	NS::map<TYPE1, TYPE2>::reverse_iterator revIt;
	std::cout << "m in reverse is:" << std::endl;
	for (revIt = m.rbegin(); revIt != m.rend(); revIt++)
		std::cout << (*revIt).first << ", " << (*revIt).second << std::endl;
	revIt = m.rend();
	revIt--;
	std::cout << "rend--; revIt: " << revIt->first << ", " << revIt->second << std::endl;
	//std::cout << "revIt[42]: " << revIt[42] << std::endl; // doesn't exist
	//std::cout << "revIt -= 1: " << (revIt -= 1) << std::endl; // doesn't exist
	
	std::cout << "\n-----CONST TESTS-----" << std::endl;

	std::cout << "constructing const from non-const map" << std::endl;
	const NS::map<TYPE1, TYPE2> constmap(m);
	std::cout << "construct non-const from const map" << std::endl;
	NS::map<TYPE1, TYPE2> m3 = constmap;

	NS::map<TYPE1, TYPE2>::iterator itr;
	std::cout << "iterator to iterator" << std::endl;
	itr = m.begin();
	NS::map<TYPE1, TYPE2>::const_iterator citr; 
	std::cout << "const_iterator to const_iterator" << std::endl;
	citr = constmap.begin();
	std::cout << "iterator to const_iterator" << std::endl;
	citr = itr;
	std::cout << "const_iterator to iterator" << std::endl;
	//itr = citr; // should not compile
}

int main()
{
	vectorTests();
	stackTests();
	mapTests();

}