#pragma once

#include <iostream>

template<typename T>
class MyList
{
	struct node {
		T data;
		node* next;
	};
	node* head;
	node* tail;
	node* current = NULL;
	node* prev = NULL;
	// можете объявить и другие указатели, какие посчитаете нужными
	size_t size;
	
	void find(T value);

public:
	MyList();
	~MyList();
	bool init(T elem); // вставка первого элемента в пустой список
	bool push_front(T elem);
	bool push_back(T elem);
	bool insert(T elem, T pos);
	bool erase(T value);
	bool pop_front();
	bool pop_back();
	void pretty_print();
};

template<typename T>
inline void MyList<T>::find(T value)
{
	node* tmp = head;
	prev=current = NULL;

	while (tmp != NULL){
		if (tmp->data == value){
			current = tmp;
			break;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

template<typename T>
inline MyList<T>::MyList() 
	: head(NULL)
	, tail(NULL)
	, size(0)
{
}

template<typename T>
inline MyList<T>::~MyList()
{
	while (size != 0){
		pop_back();
		--size;
	}
}

template<typename T>
inline bool MyList<T>::init(T elem)
{
	node* tmp = new node;
	tail = tmp;
	head = tmp;
	tmp->data = elem;
	tmp->next = NULL;
	++size;
	if (tail == NULL || head == NULL)
		return false;
	else
		return true;
}

template<typename T>
inline bool MyList<T>::push_front(T elem)
{
	if (head == NULL){
		init(elem);
		return true;
	}

	node* first = new node;
	first->data = elem;
	first->next = head;
	head = first;
	++size;
	return true;
}

template<typename T>
inline bool MyList<T>::push_back(T elem)
{
	if (head == NULL){
		init(elem);
		return true;
	}
	node* last = new node;
	last->data = elem;
	tail->next = last;
	tail = last;
	last->next = NULL;
	++size;
	return true;
}

template<typename T>
inline bool MyList<T>::insert(T elem, T pos)
{
	if (head == NULL){
		return false;
	}
	find(pos);
	if (current == NULL){
		std::cout << "no member" << std::endl;
		return false;
	}
	if (current == tail){
		push_back(elem);
		return true;
	}

	node* tmp = new node;
	tmp->data = elem;
	tmp->next = current->next;
	current->next = tmp;
	++size;
	return true;
}

template<typename T>
inline bool MyList<T>::erase(T value)
{
	find(value);
	if (current == NULL){
		return false;
	}
	//TODO if last elem, if 1st element
	if (size == 1){ pop_front(); return true; }
	if (head == current) { pop_front(); return true; }
	if (current == tail) { pop_back(); return true; }

	node* tmp = current;
	prev->next = current->next;
	--size;
	delete tmp;
	return false;
}

template<typename T>
inline bool MyList<T>::pop_front()
{
	if (head == NULL) 
		return false;
	
	if (head->next == NULL)
	{
		node* tmp = head;
		delete head;
		tail = head = NULL;
		--size;
		return true;
	}
	
	node* tmp = head;
	head = head->next;
	--size;
	delete tmp;
	return false;
}

template<typename T>
inline bool MyList<T>::pop_back()
{
	if (tail == NULL){
		return false;
	}
	node* tmp = tail;
	find(tmp->data);
	if (prev){
		prev->next = NULL;
		tail = prev;
	}
	else { head = tail = NULL;  }
	--size;
	delete tmp;
	return false;
}

template<typename T>
inline void MyList<T>::pretty_print()
{
	node* tmp = head;
	while (tmp){
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}
