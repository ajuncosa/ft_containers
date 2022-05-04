#include <iostream>
#include <map>
#include "map.hpp"


int main()
{
	std::map<int, std::string> stdmap;
	stdmap.insert(std::pair<int, std::string>(20, "edad"));
	stdmap.insert(std::pair<int, std::string>(3, "amigos"));
	std::map<int, std::string>::const_iterator stdit = stdmap.begin();
	std::map<int, std::string>::const_iterator stdit2(stdit);

	std::cout << "stdmap contains:" <<std::endl;
	for (std::map<int, std::string>::const_iterator it = stdmap.begin(); it != stdmap.end(); it++)
		std::cout << "\t" << it->first << ", " << it->second << std::endl;

	ft::map<int, std::string> ftmap;
	ftmap.insert(ft::pair<int, std::string>(20, "edad"));
	ftmap.insert(ft::pair<int, std::string>(3, "amigos"));
	ft::map<int, std::string>::const_iterator it = ftmap.begin();
	ft::map<int, std::string>::const_iterator it2(it);

	std::cout << "ftmap contains:" <<std::endl;
	for (ft::map<int, std::string>::const_iterator it = ftmap.begin(); it != ftmap.end(); it++)
		std::cout << "\t" << it->first << ", " << it->second << std::endl;

	//it2 = it;

	/*for (int i = 0; i < 2000; i++)
	{
		if (i%2 == 0)
			stdmap.insert(std::pair<int, std::string>(i/2, "par"));
		else
			stdmap.insert(std::pair<int, std::string>(i*2, "impar"));
	}*/

	/*for (int i = 0; i < 2000; i++)
	{
		if (i%2 == 0)
			ftmap.insert(ft::pair<int, std::string>(i/2, "par"));
		else
			ftmap.insert(ft::pair<int, std::string>(i*2, "impar"));
	}*/


}