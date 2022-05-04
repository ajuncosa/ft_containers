#include <iostream>
#include <map>
#include "map.hpp"
#include "binarySearchTree.hpp"


int main()
{
	/*std::map<int, std::string> stdmap;
	stdmap.insert(std::pair<int, std::string>(20, "edad"));
	stdmap.insert(std::pair<int, std::string>(3, "amigos"));
	stdmap.insert(std::pair<int, std::string>(30, "b"));
	stdmap.insert(std::pair<int, std::string>(2, "c"));
	stdmap.insert(std::pair<int, std::string>(35, "d"));
	stdmap.insert(std::pair<int, std::string>(5, "jrjr"));
	stdmap.insert(std::pair<int, std::string>(42, "u"));
	stdmap.insert(std::pair<int, std::string>(1, ">:p"));
	stdmap.insert(std::pair<int, std::string>(100, "aaaa"));

	std::map<int, std::string>::const_iterator stdit = stdmap.begin();
	std::map<int, std::string>::const_iterator stdit2(stdit);

	std::cout << "stdmap contains:" <<std::endl;
	for (std::map<int, std::string>::const_iterator it = stdmap.begin(); it != stdmap.end(); it++)
		std::cout << "\t" << it->first << ", " << it->second << std::endl;

	ft::map<int, std::string> ftmap;
	ftmap.insert(ft::pair<int, std::string>(20, "edad"));
	ftmap.insert(ft::pair<int, std::string>(3, "amigos"));
	ftmap.insert(ft::pair<int, std::string>(30, "b"));
	ftmap.insert(ft::pair<int, std::string>(2, "c"));
	ftmap.insert(ft::pair<int, std::string>(35, "d"));
	ftmap.insert(ft::pair<int, std::string>(5, "jrjr"));
	ftmap.insert(ft::pair<int, std::string>(42, "u"));
	ftmap.insert(ft::pair<int, std::string>(1, ">:p"));
	ftmap.insert(ft::pair<int, std::string>(100, "aaaa"));
	ft::map<int, std::string>::const_iterator it = ftmap.begin();
	ft::map<int, std::string>::const_iterator it2(it);

	std::cout << "ftmap contains:" <<std::endl;
	for (ft::map<int, std::string>::const_iterator it = ftmap.begin(); it != ftmap.end(); it++)
		std::cout << "\t" << it->first << ", " << it->second << std::endl;

	ftmap.printMap();
*/
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

	ft::binarySearchTree<int, std::string> bst;
	bst.insert(ft::pair<int, std::string>(0, "edad"));
	bst.insert(ft::pair<int, std::string>(2, "amigos"));
	bst.insert(ft::pair<int, std::string>(70, "enemigos"));
	bst.insert(ft::pair<int, std::string>(4, "novios"));
	bst.insert(ft::pair<int, std::string>(5, "osos"));
	bst.insert(ft::pair<int, std::string>(1, "cacas"));
	bst.insert(ft::pair<int, std::string>(30, "cucu"));
	bst.insert(ft::pair<int, std::string>(4, "repe"));
	bst.insert(ft::pair<int, std::string>(100, "cien"));

	bst.printTree();
}