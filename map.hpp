#pragma once

namespace ft
{
	template <class Key, class T, class Compare = less<Key>, class Alloc = allocator<pair<const Key,T> > >
	class map
	{
		public:
			typedef Key key_type;
			typedef T mapped_type;
			//typedef pair<const key_type,mapped_type> value_type;
			typedef Compare key_compare;
			//typedef value_compare;
			typedef Alloc allocator_type;
			typedef allocator_type::reference reference;
			typedef allocator_type::const_reference const_reference;
			typedef allocator_type::pointer pointer;
			typedef allocator_type::const_pointer const_pointer;
			//typedef iterator;
			//typedef const_iterator;
			//typedef reverse_iterator;
			//typedef const_reverse_iterator;
			//typedef iterator_traits<iterator>::difference_type difference_type
			typedef size_t size_type;

		private:
			class Node
			{
				Node		&left;
				Node		&right;
				Node		&parent;
				key_type	key;
				mapped_type	value;
			};
			
			Node *_root;
			Node *_sentinel;
	};
}
