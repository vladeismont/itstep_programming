#pragma once
#include <vector>

template <class T>
class Queue
{
private:
	std::vector<T> data;
	size_t tail;
	int size_;
	// добавьте ещё поля, какие посчитаете нужными
public:
	Queue(const Queue<T>& q);
	void clear();
	Queue<T>& operator=(const Queue<T>& q);	//Queue& operator=(const Queue<T>& q);
	int size() const;
	bool empty() const;
	void push(const T& item);
	T& pop();
	T& back();
	T& front();
	Queue() :tail(0), size_(0) {};
	~Queue();
};

template<class T>
inline void Queue<T>::push(const T & item)
{
	data.push_back(item);
	++tail;
	++size_;
}

template<class T>
inline T & Queue<T>::pop()
{
	T tmp = data[0];
	//data.pop_back();
	data.erase(data.begin() + 0);
	--tail;
	--size_;
	return tmp;
	// TODO: insert return statement here
}

template<class T>
inline T & Queue<T>::back()
{
	return data[tail-1];
	// TODO: insert return statement here
}

template<class T>
inline T & Queue<T>::front()
{
	// TODO: insert return statement here
	return data[0];
}

template<class T>
inline Queue<T>::~Queue()
{
	clear();
}

template<class T>
inline void Queue<T>::clear() {
	size_t t = tail;
	for (size_t i = 0; i < t; ++i) {
		data.pop_back();
		--size_;
		--tail;
	}
}

template<class T>
inline Queue<T> & Queue<T>::operator=(const Queue<T>& q)
{
	Queue<T> obj(q);
	return obj;
	// TODO: insert return statement here
}

template<class T>
inline Queue<T>::Queue(const Queue<T>& q) {
	for (size_t i = 0; i < q.tail; ++i) {
		data.push_back(q.data[i]);
	}
	size_ = q.size_;
	tail = q.tail;
}

template<class T>
inline int Queue<T>::size() const{
	return size_;
}

template<class T>
inline bool Queue<T>::empty() const
{
	if(tail==0)	return true;
	else return false;
}
