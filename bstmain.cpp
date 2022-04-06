#include <iostream>
#include <map>
#include "binarySearchTree.hpp"
#include "bstIterator.hpp"
#include "node.hpp"
#include <vector>

int main()
{
	ft::binarySearchTree<std::string, int> bst;
	bst.insert(ft::pair<std::string, int>("edad", 10));
	bst.insert(ft::pair<std::string, int>("amigos", 2));
	bst.insert(ft::pair<std::string, int>("novios", 4));
	bst.insert(ft::pair<std::string, int>("osos", 5));
	bst.insert(ft::pair<std::string, int>("cacas", 1));
	bst.insert(ft::pair<std::string, int>("enemigos", 70));
	
	/*ft::binarySearchTree<std::string, int>::iterator it = bst.begin();
	ft::binarySearchTree<std::string, int>::iterator it2(it);
	std::cout << "begin: " << it->value.first << std::endl;
	std::cout << "it == it2? " << (it == it2) << std::endl;*/

	//for (ft::binarySearchTree<std::string, int>::iterator it = bst.begin(); it != bst.end(); it++)
	//	std::cout << "value: " << it->first << ", " << (*it).second << std::endl;

/*	ft::binarySearchTree<std::string, int>::iterator it = bst.begin();
	//FIXME: por que esto no entra en el copy constructor >:(
	ft::binarySearchTree<std::string, int>::iterator it2(it);
	//FIXME: por que esto no entra en el assignment operator??? >:(
	//ft::binarySearchTree<std::string, int>::iterator it2 = it;
	while (it2 != bst.end())
	{
		std::cout << "value: " << it2->first << ", " << (*it2).second << std::endl;
		it2++;
	}*/
ft::binarySearchTree<std::string, int>::const_iterator it = bst.begin(); 
//	for (ft::binarySearchTree<std::string, int>::const_iterator it = bst.begin(); it != bst.end(); it++)
//		std::cout << "value: " << it->first << ", " << (*it).second << std::endl;


	/*std::map<std::string, int> map;

	map.insert(std::pair<std::string, int>("edad", 10));
	map.insert(std::pair<std::string, int>("amigos", 2));
	map.insert(std::pair<std::string, int>("novios", 4));
	std::map<std::string, int>::iterator sit = map.begin();
	std::map<std::string, int>::iterator sit2(sit);
	std::map<std::string, int>::iterator sit3 = ++sit;
	std::cout << "sit " << sit->first <<std::endl;
	std::cout << "sit2 " << sit2->first <<std::endl;
	std::cout << "sit3 " << sit3->first <<std::endl;

	std::cout << "sit == sit2? " << (sit == sit2) << std::endl;
	std::cout << "sit == sit3? " << (sit == sit3) << std::endl;*/
}
