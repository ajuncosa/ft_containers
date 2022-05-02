#include <iostream>
#include <map>
#include "map.hpp"


int main()
{
	std::map<int, std::string> stdmap;
	stdmap.insert(std::pair<int, std::string>(0, "edad"));
	stdmap.insert(std::pair<int, std::string>(2, "amigos"));
	std::map<int, std::string>::const_iterator stdit = stdmap.begin();
	std::map<int, std::string>::const_iterator stdit2(stdit);

	ft::map<int, std::string> ftmap;
	ftmap.insert(ft::pair<int, std::string>(0, "edad"));
	ftmap.insert(ft::pair<int, std::string>(2, "amigos"));
	ft::map<int, std::string>::const_iterator it = ftmap.begin();
	ft::map<int, std::string>::iterator it2(it);

	//std::cout << "---" << std::endl;

	it2 = it;
}