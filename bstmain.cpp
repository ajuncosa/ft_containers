#include <iostream>
#include "binarySearchTree.hpp"

int main()
{
	ft::binarySearchTree<std::string, int> bst;
	bst.insert(ft::pair<std::string, int>("edad", 10));
	bst.insert(ft::pair<std::string, int>("amigos", 2));
	bst.insert(ft::pair<std::string, int>("novios", 4));
}
