#pragma once

namespace ft
{
	template <class T, class Container = vector<T> >
	class stack
	{
		public:
			typedef T value_type;
			typedef Container container_type;
			typedef size_t size_type;

			explicit stack(const container_type& ctnr = container_type()) : _data(ctnr) {}

			bool empty() const
			{
				return this->_data.empty();
			}

			size_type size() const
			{
				return this->_data.size();
			}

			value_type& top()
			{
				return this->_data.back();
			}

			const value_type& top() const
			{
				return this->_data.back();
			}

			void push(const value_type& val)
			{
				this->_data.push_back(val);
			}

			void pop()
			{
				this->_data.pop_back();
			}

		private:
			container_type	_data;
	};
}
