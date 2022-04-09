#pragma once

namespace ft
{
	template <class T>
	struct Node
	{
		typedef	T value_type;

		Node		*left;
		Node		*right;
		Node		*parent;
		value_type	value;

		Node() : parent(NULL), left(NULL), right(NULL), value() {}
		
		Node(Node *parent, Node *left, Node *right, value_type value) : parent(parent), left(left), right(right), value(value) {}
		
		template <class U>
		Node(const Node<U> &src) : parent(src.parent), left(src.left), right(src.right), value(src.value) {}
		
		Node(const Node &src) : parent(src.parent), left(src.left), right(src.right), value(src.value) {}

		Node &operator=(const Node &src)
		{
			if (this != &src)
			{
				this->left = src.left;
				this->right = src.right;
				this->parent = src.parent;
				this->value = src.value;
			}
			return *this;
		}

		~Node() {}
	};
}
