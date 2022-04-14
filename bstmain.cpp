#include <iostream>
#include <map>
#include "binarySearchTree.hpp"
#include "bstIterator.hpp"
#include "node.hpp"
#include <vector>

int main()
{
	ft::binarySearchTree<int, std::string> bst;
	std::cout << "bst size: " << bst.getSize() << std::endl;
	bst.insert(ft::pair<int, std::string>(0, "edad"));
	bst.insert(ft::pair<int, std::string>(2, "amigos"));
	bst.insert(ft::pair<int, std::string>(4, "novios"));
	bst.insert(ft::pair<int, std::string>(5, "osos"));
	bst.insert(ft::pair<int, std::string>(1, "cacas"));
	bst.insert(ft::pair<int, std::string>(70, "enemigos"));
	bst.insert(ft::pair<int, std::string>(30, "cucu"));
	bst.insert(ft::pair<int, std::string>(4, "repe"));

	std::cout << "bst size: " << bst.getSize() << std::endl;

	
	ft::binarySearchTree<int, std::string>::const_iterator it = bst.begin();
	ft::binarySearchTree<int, std::string>::iterator it2(it);
	std::cout << "bst begin: " << it->first << ", " << it->second << std::endl;
	std::cout << "it == it2? " << (it == it2) << std::endl;
	*it++;
	it2++;
	std::cout << "it == it2? " << (it == it2) << std::endl;
	/*while (it2 != bst.end())
	{
		std::cout << "value: " << it2->first << ", " << (*it2).second << std::endl;
		++it2;
	}*/
	std::cout << "FULL TREE:" << std::endl;
	for (ft::binarySearchTree<int, std::string>::const_iterator iter = bst.begin(); iter != bst.end(); iter++)
		std::cout << "value: " << iter->first << ", " << iter->second << std::endl;
/*	std::cout << "----" << std::endl;
	it = bst.begin();
	std::cout << "value: " << it->first << ", " << (*it).second << std::endl;
	it++;
	std::cout << "value: " << it->first << ", " << (*it).second << std::endl;
	it--;
	std::cout << "value: " << it->first << ", " << (*it).second << std::endl;
	it = bst.end();
	//std::cout << "value: " << it->first << ", " << (*it).second << std::endl;
	it--;
	std::cout << "value: " << it->first << ", " << (*it).second << std::endl;
	it--;
	std::cout << "value: " << it->first << ", " << (*it).second << std::endl;
*/
	bst.eraseNode(it.getData());
	std::cout << "FULL TREE AFTER ERASING:" << std::endl;
	for (ft::binarySearchTree<int, std::string>::const_iterator iter = bst.begin(); iter != bst.end(); iter++)
		std::cout << "value: " << iter->first << ", " << iter->second << std::endl;
	std::cout << "bst size: " << bst.getSize() << std::endl;


/*	for (ft::binarySearchTree<std::string, int>::const_iterator it = bst.begin(); it != bst.end(); it++)
		std::cout << "value: " << it->first << ", " << (*it).second << std::endl;
	
	ft::binarySearchTree<std::string, int>::iterator it = bst.begin();
	std::cout << "cambiando: " << it->first << ", " << (*it).second << std::endl;
	(*it).second = 8;
	std::cout << "value: " << it->first << ", " << (*it).second << std::endl;
*/

	ft::binarySearchTree<int, std::string> bstcopy(bst);
	std::cout << "COPIED TREE:" << std::endl;
	for (ft::binarySearchTree<int, std::string>::const_iterator iter = bstcopy.begin(); iter != bstcopy.end(); iter++)
		std::cout << "value: " << iter->first << ", " << iter->second << std::endl;
	std::cout << "bstcopy size: " << bstcopy.getSize() << std::endl;

/*	std::map<std::string, int> map;

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
	std::cout << "sit == sit3? " << (sit == sit3) << std::endl;
	sit = map.end();
	std::cout << "sit " << sit->first << ", " << sit->second <<std::endl;
	sit--;
	std::cout << "sit " << sit->first << ", " << sit->second<<std::endl;
	sit = map.begin();
	std::cout << "sit " << sit->first << ", " << sit->second<<std::endl;
	sit--;
	std::cout << "sit " << sit->first << ", " << sit->second<<std::endl;
	//sit--;
	//std::cout << "sit " << sit->first << ", " << sit->second<<std::endl;
*/
/*	std::map<std::string, int>::const_iterator cit = map.begin();
	std::cout << "cambiando " << cit->first <<std::endl;
	cit->second = 8;
	for (std::map<std::string, int>::const_iterator it = map.begin(); it != map.end(); it++)
		std::cout << "value: " << it->first << ", " << (*it).second << std::endl;
	*/
}
