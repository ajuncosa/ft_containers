#include <iostream>
#include <map>
#include <list>
#include "map.hpp"
#include "binarySearchTree.hpp"


int main()
{
/*	std::map<int, std::string> stdmap;
	stdmap.insert(std::pair<int, std::string>(20, "edad"));
	stdmap.insert(std::pair<int, std::string>(3, "amigos"));
	stdmap.insert(std::pair<int, std::string>(30, "b"));
	stdmap.insert(std::pair<int, std::string>(2, "c"));
	stdmap.insert(std::pair<int, std::string>(35, "d"));
	stdmap.insert(std::pair<int, std::string>(5, "jrjr"));
	stdmap.insert(std::pair<int, std::string>(42, "u"));
	stdmap.insert(std::pair<int, std::string>(1, ">:p"));
	stdmap.insert(std::pair<int, std::string>(100, "aaaa"));
*/
/*	std::map<int, std::string>::const_iterator stdit = stdmap.begin();
	std::map<int, std::string>::const_iterator stdit2(stdit);

	std::cout << "stdmap contains:" <<std::endl;
	for (std::map<int, std::string>::const_iterator it = stdmap.begin(); it != stdmap.end(); it++)
		std::cout << "\t" << it->first << ", " << it->second << std::endl;
*/

/*	typedef ft::map<int, int>::value_type T;
	std::list<T> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T(i + 1, (i + 1) * 3));
	ft::map<int, int> ftmap(lst.begin(), lst.end());

	for (ft::map<int, int>::const_iterator it = ftmap.begin(); it != ftmap.end(); it++)
		std::cout << "\t" << it->first << ", " << it->second << std::endl;

	ft::map<int, int>::const_iterator last = --ftmap.end();
	std::cout << "begin: " << ftmap.begin()->first << ", end - 1: " << last->first << std::endl;
	*/

	ft::map<int, std::string> ftmap;
/*	ftmap.insert(ft::pair<int, std::string>(20, "edad"));
	ftmap.insert(ft::pair<int, std::string>(3, "amigos"));
	ftmap.insert(ft::pair<int, std::string>(30, "b"));
	ftmap.insert(ft::pair<int, std::string>(2, "c"));
	ftmap.insert(ft::pair<int, std::string>(35, "d"));
	ftmap.insert(ft::pair<int, std::string>(5, "jrjr"));
	ftmap.insert(ft::pair<int, std::string>(42, "u"));
	ftmap.insert(ft::pair<int, std::string>(1, ">:p"));
	ftmap.insert(ft::pair<int, std::string>(100, "aaaa"));
*/
/*	ft::map<int, std::string>::const_iterator it = ftmap.begin();
	ft::map<int, std::string>::const_iterator it2(it);

	std::cout << "ftmap contains:" <<std::endl;
	for (ft::map<int, std::string>::const_iterator it = ftmap.begin(); it != ftmap.end(); it++)
		std::cout << "\t" << it->first << ", " << it->second << std::endl;
	*/
	/*ftmap.printMap();
	ftmap.erase(20);
	ftmap.erase(100);
	ftmap.erase(2);
	ftmap.erase(3);
	ftmap.erase(35);
	ftmap.erase(30);
	*/


	ftmap.insert(ft::pair<int, std::string>(384, "n"));
	ftmap.insert(ft::pair<int, std::string>(158, "n"));
	ftmap.insert(ft::pair<int, std::string>(593, "n"));
	ftmap.insert(ft::pair<int, std::string>(30, "n"));
	ftmap.insert(ft::pair<int, std::string>(238, "n"));
	ftmap.insert(ft::pair<int, std::string>(531, "n"));
	ftmap.insert(ft::pair<int, std::string>(754, "n"));
	ftmap.insert(ft::pair<int, std::string>(3, "n"));
	ftmap.insert(ft::pair<int, std::string>(100, "n"));
	ftmap.insert(ft::pair<int, std::string>(222, "n"));
	ftmap.insert(ft::pair<int, std::string>(257, "n"));
	ftmap.insert(ft::pair<int, std::string>(511, "n"));
	ftmap.insert(ft::pair<int, std::string>(546, "n"));
	ftmap.insert(ft::pair<int, std::string>(690, "n"));
	ftmap.insert(ft::pair<int, std::string>(917, "n"));
	ftmap.insert(ft::pair<int, std::string>(2, "n"));
	ftmap.insert(ft::pair<int, std::string>(5, "n"));
	ftmap.insert(ft::pair<int, std::string>(69, "n"));
	ftmap.insert(ft::pair<int, std::string>(152, "n"));
	ftmap.insert(ft::pair<int, std::string>(197, "n"));
	ftmap.insert(ft::pair<int, std::string>(223, "n"));
	ftmap.insert(ft::pair<int, std::string>(242, "n"));
	ftmap.insert(ft::pair<int, std::string>(353, "n"));
	ftmap.insert(ft::pair<int, std::string>(509, "n"));
	ftmap.insert(ft::pair<int, std::string>(514, "n"));
	ftmap.insert(ft::pair<int, std::string>(640, "n"));
	ftmap.insert(ft::pair<int, std::string>(699, "n"));
	ftmap.insert(ft::pair<int, std::string>(820, "n"));
	ftmap.insert(ft::pair<int, std::string>(971, "n"));
	ftmap.insert(ft::pair<int, std::string>(1, "n"));
	ftmap.insert(ft::pair<int, std::string>(42, "n"));
	ftmap.insert(ft::pair<int, std::string>(71, "n"));
	ftmap.insert(ft::pair<int, std::string>(232, "n"));
	ftmap.insert(ft::pair<int, std::string>(350, "n"));
	ftmap.insert(ft::pair<int, std::string>(356, "n"));
	ftmap.insert(ft::pair<int, std::string>(638, "n"));
	ftmap.insert(ft::pair<int, std::string>(661, "n"));
	ftmap.insert(ft::pair<int, std::string>(697, "n"));
	ftmap.insert(ft::pair<int, std::string>(750, "n"));
	ftmap.insert(ft::pair<int, std::string>(782, "n"));
	ftmap.insert(ft::pair<int, std::string>(881, "n"));
	ftmap.insert(ft::pair<int, std::string>(949, "n"));
	ftmap.insert(ft::pair<int, std::string>(994, "n"));
	ftmap.insert(ft::pair<int, std::string>(92, "n"));
	ftmap.insert(ft::pair<int, std::string>(304, "n"));
	ftmap.insert(ft::pair<int, std::string>(664, "n"));
	ftmap.insert(ft::pair<int, std::string>(722, "n"));
	ftmap.insert(ft::pair<int, std::string>(756, "n"));
	ftmap.insert(ft::pair<int, std::string>(930, "n"));

	ftmap.erase(384);
	ftmap.erase(531);
	ftmap.erase(100);
	ftmap.erase(3);
	ftmap.erase(238);
	ftmap.erase(223);
	ftmap.erase(152);
	ftmap.erase(71);
	ftmap.erase(257);
	ftmap.erase(304);
	ftmap.erase(222);
	ftmap.erase(232);
	ftmap.erase(242);
	ftmap.erase(350);
	ftmap.erase(353);
	ftmap.erase(158);
	ftmap.erase(197);
	ftmap.erase(69);
	ftmap.erase(30);
	ftmap.erase(509);
	ftmap.erase(42);
	ftmap.erase(640);
	ftmap.erase(699);
	ftmap.erase(356);
	ftmap.erase(511);
	ftmap.erase(514);
	ftmap.erase(690);


	ftmap.printMap();
	std::cout << "size: " << ftmap.size() << std::endl;;



	//it2 = it;

	/*for (int i = 0; i < 20000; i++)
	{
		if (i%2 == 0)
			stdmap.insert(std::pair<int, std::string>(i/2, "par"));
		else
			stdmap.insert(std::pair<int, std::string>(i*2, "impar"));
	}
	for (int i = 0; i < 20000; i++)
	{
		stdmap.erase(i);
	}
*/
	/*for (int i = 0; i < 50000; i++)
	{
		ftmap.insert(ft::pair<int, std::string>(i, "par"));
	}

	for (int i = 0; i < 20000; i++)
	{
		ftmap.erase(i);
	}
	for (int i = 21000; i < 50000; i+=100)
		ftmap.find(i);*/
	//ftmap.printMap();


	/*ft::binarySearchTree<int, std::string> bst;
	bst.insert(ft::pair<int, std::string>(0, "edad"));
	bst.insert(ft::pair<int, std::string>(2, "amigos"));
	bst.insert(ft::pair<int, std::string>(70, "enemigos"));
	bst.insert(ft::pair<int, std::string>(4, "novios"));
	bst.insert(ft::pair<int, std::string>(5, "osos"));
	bst.insert(ft::pair<int, std::string>(1, "cacas"));
	bst.insert(ft::pair<int, std::string>(30, "cucu"));
	bst.insert(ft::pair<int, std::string>(4, "repe"));
	bst.insert(ft::pair<int, std::string>(100, "cien"));

	for (ft::binarySearchTree<int, std::string>::const_iterator it=bst.begin(); it != bst.end(); it++)
		std::cout << it->first << ", " << it->second << std::endl;

	bst.printTree();*/


}