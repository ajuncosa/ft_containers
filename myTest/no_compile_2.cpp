#include <iostream>
#include <map>
#include "../map.hpp"
#include "../pair.hpp"

#define TYPE1 int
#define TYPE2 std::string

int main()
{
	NS::map<TYPE1, TYPE2> m;
	m.insert(NS::pair<TYPE1, TYPE2>(25, "edad"));
	m.insert(NS::pair<TYPE1, TYPE2>(2, "amigos"));
	NS::map<TYPE1, TYPE2>::iterator it = m.begin();
	NS::map<TYPE1, TYPE2>::const_iterator cit(it);
	//should not compile:
	it = cit;
}