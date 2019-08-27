#pragma once
template<class T>
struct node {
	T data;
	node* next;
	node* prev;
};

template<class T>
class List
{
	node<T>* head;
	node<T>* tail;
	size_t size;
	bool init(const T& value);
public:
	List();
	~List();
	
	bool push_front(const T& value);
	bool push_back(const T& value);
	bool pop_front();
	bool pop_back();
	node<T>* find(const T& value);
	bool insert(const T& value, const T& prev_value);
	bool erase(const T& value);
	void print() const;
	void printReverse()const;
	void replaceValue(const T& value, const T& valueR);
	void eraseAll(const T& value);
};

template<class T>
List<T>::List() :head(NULL), tail(NULL), size(0)
{
}
template<class T>
List<T>::~List()
{
	while (size != 0) {
		pop_back();
	}
}

template<class T>
inline bool List<T>::init(const T& value)
{
	node<T>* newNode = new node<T>;
	newNode->data = value;
	newNode->next = NULL;
	newNode->prev = NULL;
	head = newNode;
	tail = newNode;
	++size;
	return true;
}

template<class T>
inline bool List<T>::push_front(const T& value)
{
	if (head == NULL) {
		init(value);
		return true;
	}

	node<T>* newNode = new node<T>;
	newNode->data = value;
	newNode->next = head;
	newNode->prev = NULL;
	head->prev = newNode;
	head = newNode;
	++size;
	return true;
}

template<class T>
inline bool List<T>::push_back(const T& value)
{
	if (head == NULL) {
		init(value);
		return true;
	}
	node<T>* newNode = new node<T>;
	newNode->data = value;
	newNode->next = NULL;
	newNode->prev = tail;
	tail->next = newNode;
	tail = newNode;
	++size;
	return true;
}

template<class T>
inline bool List<T>::pop_front()
{
	if (head == NULL) {
		return false;
	}
	node<T>* firstElem = head;
	head->prev = NULL;
	head = head->next;
	--size;
	delete firstElem;

	return true;
}

template<class T>
inline bool List<T>::pop_back() {
	if (tail == NULL) {
		return false;
	}
	node<T>* lastElem = tail;
	tail = tail->prev;
	if(tail!=NULL)
		tail->next = NULL;
	--size;
	delete lastElem;

	return true;
}

template<class T>
inline node<T>* List<T>::find(const T& value)
{
	if (head == NULL) {
		return NULL;
	}
	node<T>* elem = head;
	while (elem) {
		if (elem->data == value) {
			break;
		}
		else {
			elem = elem->next;
		}
	}
		return elem;
}

template<class T>
inline bool List<T>::insert(const T& value, const T& prev_value)
{
	
	node<T>* pos = find(prev_value);
	if (pos == NULL) {
		return false;
	}

	if (tail == pos) {
		push_back(value);
		return true;
	}

	node<T>* newNode = new node<T>;
	newNode->data = value;
	newNode->prev = pos;
	newNode->next = pos->next;
	pos->next->prev = newNode;
	pos->next = newNode;
	++size;
	return true;
}

template<class T>
inline bool List<T>::erase(const T& value)
{
	node<T>* pos = find(value);
	if (pos == NULL)	return false;
	if (pos == head) {
		pop_front();
		return true;
	}
	if (pos == tail) {
		pop_back();
		return true;
	}
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	--size;
	delete pos;
	return true;
}

template<class T>
inline void List<T>::print() const
{
	if (head != NULL) {
		node<T>* tmp = head;
		while (tmp) {
			std::cout << tmp->data << " ";
			tmp = tmp->next;
		}
		std::cout << std::endl;
	}
}

template<class T>
inline void List<T>::printReverse() const
{
	node<T>* tmp = tail;
	for (int i = 0; i < size; ++i) {
		std::cout << tmp->data << " ";
		tmp = tmp->prev;
	}
	std::cout << std::endl;
}

template<class T>
inline void List<T>::replaceValue(const T & value, const T & valueR)
{
	node<T>* pos = find(value);
	if (pos != NULL) {
		pos->data = valueR;
	}
}

template<class T>
inline void List<T>::eraseAll(const T & value)
{
	node<T>* n = find(value);
	while (n != NULL) {
		erase(value);
		n = find(value);
	}
}