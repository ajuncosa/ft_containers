#pragma once
#include <memory>

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
	class map
	{
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			//typedef value_compare;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			//typedef iterator;
			//typedef const_iterator;
			//typedef reverse_iterator;
			//typedef const_reverse_iterator;
			//typedef iterator_traits<iterator>::difference_type difference_type
			typedef size_t size_type;

			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				this->_size = 0;
				this->_comp = comp;
				this->_alloc = alloc;
				this->_nodeAlloc = node_alloc_type();
				this->_root = this->_nodeAlloc.allocate(1);
				this->_nodeAlloc.construct(this->_root, Node());
			}

		/*	template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				size_type count = 0;
				this->_comp = comp;
				this->_alloc = alloc;
				this->_sentinel = this->_nodeAlloc.allocate(sizeof(Node));
				this->_nodeAlloc.construct(this->_sentinel, Node());
				this->_root = _sentinel;
				for (InputIterator it = first; it != last; it++)
				{
					count++;
				}
			}*/

			/*map(const map& x)
			{

			}*/

			~map() //FIXME: provisional
			{
				std::cout << "THIS MAP CONTAINS: " << std::endl;
				Node *it;
				if (this->_root->sentinel == false)
				{
					this->_nodeAlloc.destroy(this->_root->parent);
					this->_nodeAlloc.deallocate(this->_root->parent, 1);
				}
				for (it = this->_root; it->sentinel == false; it = it->left)
				{
					std::cout << "it->value->second: " << it->value.second << std::endl;
					this->_nodeAlloc.destroy(it);
					this->_nodeAlloc.deallocate(it, 1);
				}
				this->_nodeAlloc.destroy(it);
				this->_nodeAlloc.deallocate(it, 1);
			}

			void fake_insert(const value_type &data) //FIXME: provisional
			{
				Node *tmp;
				Node *sentinelOne;
				//Node *sentinelTwo;
				sentinelOne = this->_nodeAlloc.allocate(1);
				this->_nodeAlloc.construct(sentinelOne, Node());
				//sentinelTwo = this->_nodeAlloc.allocate(1);
				//this->_nodeAlloc.construct(sentinelTwo, Node());
				if (this->_root->sentinel == true)
				{
					tmp = this->_root;
					this->_root = this->_nodeAlloc.allocate(1);
					sentinelOne->parent = this->_root;
					//sentinelTwo->parent = this->_root;
					//FIXME: cambiar NULL por sentinelTwo
					this->_nodeAlloc.construct(this->_root, Node(sentinelOne, NULL, tmp, data));
				}
				else
				{
					Node *it = this->_root;
					while (it->sentinel == false)
						it = it->left;
					it = it->parent;
					this->_nodeAlloc.destroy(it->left);
					this->_nodeAlloc.deallocate(it->left, 1);
					tmp = this->_nodeAlloc.allocate(1);
					sentinelOne->parent = tmp;
					//sentinelTwo->parent = tmp;
					it->left = tmp;
					//FIXME: cambiar NULL por sentinelTwo
					this->_nodeAlloc.construct(tmp, Node(sentinelOne, NULL, it, data));
				}
			}

		private:
			struct Node //FIXME: necesito alocar el value? (y desalocarlo en el destructor)
			{
				bool		sentinel;
				Node		*left;
				Node		*right;
				Node		*parent;
				value_type	value;

				Node() : sentinel(true), left(NULL), right(NULL), parent(NULL), value() {std::cout << "constructing an empty node" <<std::endl;}
				Node(Node *left, Node *right, Node *parent, value_type value) : sentinel(false), left(left), right(right), parent(parent), value(value) {std::cout << "constructing a full node" <<std::endl;}
				Node(const Node &src) : sentinel(src.sentinel), left(src.left), right(src.right), parent(src.parent), value(src.value) {std::cout << "copy constructing a node" <<std::endl;}
				Node &operator=(const Node &src)
				{
					std::cout << "assigning a node" <<std::endl;
					if (this != &src)
					{
						this->sentinel = src.sentinel;
						this->left = src.left;
						this->right = src.right;
						this->parent = src.parent;
						this->value = src.value;
					}
					return *this;
				}
				~Node() {std::cout << "destroying node" <<std::endl;}
			};

			typedef	typename allocator_type::template rebind<Node>::other node_alloc_type;

			size_type		_size;
			allocator_type	_alloc;
			node_alloc_type	_nodeAlloc;
			key_compare		_comp;
			Node			*_root;
	};
}
