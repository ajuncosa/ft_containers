#pragma once

namespace ft
{
	template <class T>
	struct Node
	{
		typedef	T value_type;

		Node				*parent;
		Node				*left;
		Node				*right;
		value_type			value;
		enum {RED, BLACK}	colour;

		Node() : parent(NULL), left(NULL), right(NULL), value(), colour(BLACK) {}
		
		Node(Node *parent, Node *left, Node *right, value_type value) : parent(parent), left(left), right(right), value(value), colour(RED) {}
		
		template <class U>
		Node(const Node<U> &src) : parent(src.parent), left(src.left), right(src.right), value(src.value), colour(src.colour) {}
		
		Node(const Node &src) : parent(src.parent), left(src.left), right(src.right), value(src.value), colour(src.colour) {}

		Node &operator=(const Node &src)
		{
			if (this != &src)
			{
				this->left = src.left;
				this->right = src.right;
				this->parent = src.parent;
				this->value = src.value;
				this->colour = src.colour;
			}
			return *this;
		}

		~Node() {}

		void recolor()
		{
			this->colour = (this->colour == RED) ? BLACK : RED;
		}
	};
}
