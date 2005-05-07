#ifndef __STACK1_H__
#define __STACK1_H__

#include <sys_types.h>

namespace std {

	template<typename T>
	class stack {

		/*
	public:
		struct const_iterator;

		struct iterator {
			iterator() STL_SECTION;
			bool operator == (const iterator &it) const STL_SECTION;
			bool operator == (const const_iterator &it) const STL_SECTION;
			bool operator != (const iterator &it) const STL_SECTION;
			bool operator != (const const_iterator &it) const STL_SECTION;

			const iterator &operator ++ (int) STL_SECTION;
			const iterator &operator += (size_t offset) STL_SECTION;
			const iterator &operator -- (int) STL_SECTION;
			const iterator &operator + (size_t offset) const STL_SECTION;
			size_t operator - (const iterator &it) const STL_SECTION;
			size_t operator - (const const_iterator &it) const STL_SECTION;

			T &operator * () const STL_SECTION;
			T *operator -> () const STL_SECTION;

		private:
			T *myPtr;

		friend struct const_iterator;
		};

		struct const_iterator {
			const_iterator() STL_SECTION;
			const_iterator(const iterator &it) STL_SECTION;

			bool operator == (const iterator &it) const STL_SECTION;
			bool operator == (const const_iterator &it) const STL_SECTION;
			bool operator != (const iterator &it) const STL_SECTION;
			bool operator != (const const_iterator &it) const STL_SECTION;

			const const_iterator &operator ++ (int) STL_SECTION;
			const const_iterator &operator += (size_t offset) STL_SECTION;
			const const_iterator &operator -- (int) STL_SECTION;
			const const_iterator &operator + (size_t offset) const STL_SECTION;
			size_t operator - (const iterator &it) const STL_SECTION;
			size_t operator - (const const_iterator &it) const STL_SECTION;

			const T &operator * () const STL_SECTION;
			const T *operator -> () const STL_SECTION;

		private:
			T *myPtr;

		friend struct iterator;
		};
	*/

	public:
		stack() STL_SECTION;
		~stack() STL_SECTION;

		bool empty() const STL_SECTION;
		size_t size() const STL_SECTION;
		T& top() const STL_SECTION;

		void push(const T &element) STL_SECTION;
		void pop() STL_SECTION;
		/*
		T& operator[] (size_t index) const STL_SECTION;
		T& back() const STL_SECTION;

		iterator begin() const STL_SECTION;
		iterator end() const STL_SECTION;

		void clear() STL_SECTION;
		void reserve(size_t size) STL_SECTION;
		void push_back(const T &element) STL_SECTION;
		void insert(const iterator &position, const const_iterator &from, const const_iterator &to) STL_SECTION;
		void swap(stack &v) STL_SECTION;
		*/

	private:
		/*
		size_t myDataSize;
		size_t myLength;
		T *myData;
		*/
	};

	template<typename T>
	inline stack<T>::stack() {
		// TODO: implement
		/*
		myDataSize = 0;
		myLength = 0;
		myData = 0;
		*/
	}
	template<typename T>
	inline stack<T>::~stack() {
		// TODO: implement
		/*
		if (myData != 0) {
			delete[] myData;
		}
		*/
	}

	/*
	template<typename T>
	inline stack<T>::iterator::iterator() {
	}
	template<typename T>
	inline stack<T>::const_iterator::const_iterator() {
	}
	template<typename T>
	inline stack<T>::const_iterator::const_iterator(const stack<T>::iterator &it) {
		myPtr = it.myPtr;
	}

	template<typename T>
	inline bool stack<T>::iterator::operator == (const stack<T>::iterator &it) const {
		return myPtr == it.myPtr;
	}
	template<typename T>
	inline bool stack<T>::iterator::operator == (const stack<T>::const_iterator &it) const {
		return myPtr == it.myPtr;
	}
	template<typename T>
	inline bool stack<T>::const_iterator::operator == (const stack<T>::iterator &it) const {
		return myPtr == it.myPtr;
	}
	template<typename T>
	inline bool stack<T>::const_iterator::operator == (const stack<T>::const_iterator &it) const {
		return myPtr == it.myPtr;
	}

	template<typename T>
	inline bool stack<T>::iterator::operator != (const stack<T>::iterator &it) const {
		return !operator == (it);
	}
	template<typename T>
	inline bool stack<T>::iterator::operator != (const stack<T>::const_iterator &it) const {
		return !operator == (it);
	}
	template<typename T>
	inline bool stack<T>::const_iterator::operator != (const stack<T>::iterator &it) const {
		return !operator == (it);
	}
	template<typename T>
	inline bool stack<T>::const_iterator::operator != (const stack<T>::const_iterator &it) const {
		return !operator == (it);
	}

	template<typename T>
	inline const stack<T>::iterator &stack<T>::iterator::operator ++ (int) {
		myPtr++;
		return *this;
	}
	template<typename T>
	inline const stack<T>::iterator &stack<T>::iterator::operator += (size_t offset) {
		myPtr += offset;
		return *this;
	}
	template<typename T>
	inline const stack<T>::iterator &stack<T>::iterator::operator -- (int) {
		myPtr--;
		return *this;
	}
	template<typename T>
	inline const stack<T>::iterator &stack<T>::iterator::operator + (size_t offset) const {
		iterator it = *this;
		it.myPtr += offset;
		return it;
	}
	template<typename T>
	inline size_t stack<T>::iterator::operator - (const stack<T>::iterator &it) const {
		return myPtr - it.myPtr;
	}
	template<typename T>
	inline size_t stack<T>::iterator::operator - (const stack<T>::const_iterator &it) const {
		return myPtr - it.myPtr;
	}
	template<typename T>
	inline const stack<T>::const_iterator &stack<T>::const_iterator::operator ++ (int) {
		myPtr++;
		return *this;
	}
	template<typename T>
	inline const stack<T>::const_iterator &stack<T>::const_iterator::operator += (size_t offset) {
		myPtr += offset;
		return *this;
	}
	template<typename T>
	inline const stack<T>::const_iterator &stack<T>::const_iterator::operator -- (int) {
		myPtr--;
		return *this;
	}
	template<typename T>
	inline const stack<T>::const_iterator &stack<T>::const_iterator::operator + (size_t offset) const {
		const_iterator it = *this;
		it.myPtr += offset;
		return it;
	}
	template<typename T>
	inline size_t stack<T>::const_iterator::operator - (const stack<T>::iterator &it) const {
		return myPtr - it.myPtr;
	}
	template<typename T>
	inline size_t stack<T>::const_iterator::operator - (const stack<T>::const_iterator &it) const {
		return myPtr - it.myPtr;
	}

	template<typename T>
	inline T &stack<T>::iterator::operator * () const {
		return *myPtr;
	}
	template<typename T>
	inline T *stack<T>::iterator::operator -> () const {
		return myPtr;
	}
	template<typename T>
	inline const T &stack<T>::const_iterator::operator * () const {
		return *myPtr;
	}
	template<typename T>
	inline const T *stack<T>::const_iterator::operator -> () const {
		return myPtr;
	}
	*/

	template<typename T>
	bool stack<T>::empty() const {
		// TODO: implement
		return true;
	}
	template<typename T>
	size_t stack<T>::size() const {
		// TODO: implement
		return 0;
	}
	template<typename T>
	T& stack<T>::top() const {
		// TODO: implement
	}
	template<typename T>
	void stack<T>::push(const T &element) {
		// TODO: implement
	}
	template<typename T>
	void stack<T>::pop() {
		// TODO: implement
	}
	/*
	template<typename T>
	T& stack<T>::operator[] (size_t index) const {
		// TODO: implement
		return front();
	}
	template<typename T>
	T& stack<T>::back() const {
		// TODO: implement
		return front();
	}

	template<typename T>
	stack<T>::iterator stack<T>::begin() const {
		// TODO: implement
		return iterator();
	}
	template<typename T>
	stack<T>::iterator stack<T>::end() const {
		// TODO: implement
		return iterator();
	}

	template<typename T>
	inline void stack<T>::clear() {
		// TODO: implement
	}
	template<typename T>
	inline void stack<T>::reserve(size_t size) {
		// TODO: implement
	}
	template<typename T>
	inline void stack<T>::push_back(const T &element) {
		// TODO: implement
	}
	template<typename T>
	inline void stack<T>::insert(const stack<T>::iterator &position, const stack<T>::const_iterator &from, const stack<T>::const_iterator &to) {
		// TODO: implement
	}
	template<typename T>
	inline void stack<T>::swap(stack<T>::stack &v) {
		// TODO: implement
	}

	template<typename T>
	inline stack<T>::const_iterator upper_bound(const stack<T>::const_iterator &start, const stack<T>::const_iterator &end, const T &value) {
		// TODO: implement
		return start;
	}
	template<typename T>
	inline stack<T>::const_iterator lower_bound(const stack<T>::const_iterator &start, const stack<T>::const_iterator &end, const T &value) {
		// TODO: implement
		return start;
	}
	*/
};

#endif /* __STACK1_H__ */
