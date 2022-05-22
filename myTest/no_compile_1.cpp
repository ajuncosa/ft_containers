#include <iostream>
#include <vector>
#include "../vector.hpp"

#define TYPE1 int
#define TYPE2 std::string

int main()
{
	NS::vector<TYPE1> const v;
	NS::vector<TYPE1>::const_iterator it = v.begin();
	// should not compile:
	NS::vector<TYPE1>::iterator it2(it);
}