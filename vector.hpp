#pragma once
#include <memory>

template <class T, class Alloc = std::allocator<T> > //TODO: catch exceptions from allocator
class vector
{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef size_t size_type;
		//typedef

		explicit vector(const allocator_type& alloc = allocator_type())
		{
			this->_size = 0;
			this->_myAllocator = alloc;
			this->_data = NULL;
		};

		explicit vector(size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type())
		{
			this->_size = n;
			this->_myAllocator = alloc;
			this->_data = this->_myAllocator.allocate(this->_size);
			for (size_type i = 0; i < this->_size; i++)
				this->_myAllocator.construct(&this->_data[i], val);
		};

	/*	template <class InputIterator>
        vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type())
		{

		};*/

		vector(const vector& x)
		{
			this->_size = x._size;
			this->_myAllocator = x.get_allocator();
			this->_data = this->_myAllocator.allocate(this->_size);
			for (size_type i = 0; i < this->_size; i++)
				this->_myAllocator.construct(&this->_data[i], x._data[i]);
		};

		vector& operator=(const vector& x)
		{
			if (this != &x)
			{
				if (this->_data)
				{
					for (size_type i = 0; i < this->_size; i++)
						this->_myAllocator.destroy(&this->_data[i]);
					this->_myAllocator.deallocate(this->_data, this->_size);
				}
				this->_size = x._size;
				this->_data = this->_myAllocator.allocate(this->_size);
				for (size_type i = 0; i < this->_size; i++)
					this->_myAllocator.construct(&this->_data[i], x._data[i]);
			}
			return *this;
		};

		~vector()
		{
			for (size_type i = 0; i < this->_size; i++)
				std::cout << this->_data[i];
			std::cout << std::endl;

			if (this->_data)
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_myAllocator.destroy(&this->_data[i]);
				this->_myAllocator.deallocate(this->_data, this->_size);
			}
		};

		allocator_type get_allocator() const
		{
			return this->_myAllocator;
		};

		size_type size() const
		{
			return this->_size;
		};

		size_type max_size() const
		{
			return this->_myAllocator.max_size();
		};

		bool empty() const
		{
			return this->_size == 0 ? true : false;
		};

	private:
		value_type		*_data;
		size_type		_size;
		allocator_type	_myAllocator;
};
