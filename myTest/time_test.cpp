#include <iostream>
#include <map>
#include "../map.hpp"

#define TYPE1 int
#define TYPE2 std::string

int main()
{
	NS::map<TYPE1, TYPE2> m;

	for (int i = 0; i < 100000; i++)
		m.insert(NS::pair<TYPE1, TYPE2>(i, "a"));

	for (int i = 0; i < 100000; i++)
		m.erase(i);

	for (int i = 21000; i < 50000; i+=100)
		m.find(i);
}