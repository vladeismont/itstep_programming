#pragma once
template<typename T>
class BinaryTree {
	struct node {
		T data;
		node* left, *right, *prev;
	};
	size_t size;
	node* root;
	bool deletecurr(node* curr, const T value);
public:
	BinaryTree();
	~BinaryTree();
	void freeTree(node* root);
	bool isEmpty() const { return root == NULL; }
	void insert(T d);
	void print() { inorder(root); }
	void inorder(node* p);
	bool find(T d)const;
	BinaryTree(const BinaryTree& other);
	BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& obj);
	T getMin();
	T getMax();
	size_t getSize();
	bool deleteValue(const T value);
};

template<typename T>
inline bool BinaryTree<T>::deletecurr(node * curr, const T value)
{
	node* tmp = curr->prev;
	if (value < tmp->data) {
		if (tmp->left->left && tmp->left->right==NULL) {	//#1 work
			tmp->left = tmp->left->left;
			if (tmp->left != NULL) {
				tmp->left->prev = tmp;
			}
			--size;
			delete curr;
			return true;
		}
		if (tmp->left->left == NULL) {	//#2 work
			if (tmp->left->right) tmp->left->right->prev = tmp;
			tmp->left = tmp->left->right;
			--size;
			delete curr;
			return true;
		}
		if (tmp->left->left && tmp->left->right) {	//#3 work with error
			if (tmp->left->right->left){ std::cout << "cant delete " << value << ". (" << curr->data << " - persists)" << std::endl; return false; }
			tmp->left->right->left = tmp->left->left;	//here is this problem
			tmp->left->left->prev = tmp->left->right;
			tmp->left->right->prev = tmp;
			tmp->left = tmp->left->right;
			--size;
			delete curr;
			return true;
		}
	}
	else {
		if (tmp->right->left && tmp->right->right == NULL) {	//#1
			tmp->right = tmp->right->left;
			if (tmp->right != NULL) {
				tmp->right->prev = tmp;
			}
			--size;
			delete curr;
			return true;
		}
		if (tmp->right->left == NULL) {	//#2
			if(tmp->right->right) tmp->right->right->prev = tmp->right;
			tmp->right = tmp->right->right;
			--size;
			delete curr;
			return true;
		}
		if (tmp->right->left && tmp->right->right) {	//#3
			if (tmp->right->right->left) { std::cout << "cant delete " << value << ". (" << curr->data << " - persists)" << std::endl; return false; }
			tmp->right->right->left = tmp->right->left;	//here is this problem
			tmp->right->left->prev = tmp->right->right;
			tmp->right->right->prev = tmp;
			tmp->right = tmp->right->right;
			--size;
			delete curr;
			return true;
		}
	}
}

template<typename T>
inline BinaryTree<T>::BinaryTree()
{
	root = NULL; size = 0;
}

template<typename T>
inline BinaryTree<T>::~BinaryTree()
{
	freeTree(root);
}

template<typename T>
inline void BinaryTree<T>::freeTree(node* node) {
	if (node == NULL) return;
	freeTree(node->left);
	freeTree(node->right);
	--size;
	delete node;
}

template<typename T>
void BinaryTree<T>::insert(T d)
{
	node* t = new node;
	node* parent;
	t->data = d;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;
	++size;
	t->prev = NULL;
	// is this a new tree?
	if (isEmpty()) root = t;
	else
	{
		//Note: ALL insertions are as leaf nodes
		node* curr;
		curr = root;
		// Find the Node's parent
		while (curr)
		{
			parent = curr;
			if (t->data > curr->data) curr = curr->right;
			else curr = curr->left;
			if (parent->data == d) {
				std::cout << "cant insert " << parent->data << " - already persists" << std::endl;
				return;
			}
		}
		if (t->data < parent->data) {
			parent->left = t; t->prev = parent;
		}
		else {
			parent->right = t; t->prev = parent;
		}
	}
}

template<typename T>
void BinaryTree<T>::inorder(node* p) {
	if (p != NULL) {
		if (p->left) inorder(p->left);
		std::cout << p->data << " ";
		if (p->right) inorder(p->right);
	}
	else 
		return;
}

template<typename T>
bool BinaryTree<T>::find(T d)const {
	node* curr = root;
	while (curr) {
		if (curr->data == d) return true;
		else
			if (d < curr->data) curr = curr->left;
			else
				//if (d > curr->data)		// d!=curr->data
					curr = curr->right;
	}
	if (curr == NULL) return false;
}

template<typename T>
inline BinaryTree<T>::BinaryTree(const BinaryTree & other)
{
	root = NULL;
	std::vector<node const*> remaining;	//указатель нельзя поменять const
	node const* cur = other.root;
	while (cur) {
		insert(cur->data);
		if (cur->right) {
			remaining.push_back(cur->right);	//если есть куда идти вправо вставляем правый узел
		}
		if (cur->left) {
			cur = cur->left;	//если есть куда идти влево
		}
		else 
			if (remaining.empty()) {
				break;
			}
			else {
				cur = remaining.back();
				remaining.pop_back();
			}
	}
	size = other.size;
}

template<typename T>
inline BinaryTree<T> & BinaryTree<T>::operator=(const BinaryTree<T> & obj)
{
	freeTree(root);
	BinaryTree<T> th(obj);
	return th;
	// TODO: insert return statement here
}

template<typename T>
inline T BinaryTree<T>::getMin()
{
	node* curr = root;
	T tmp = curr->data;
	while (curr) {
		tmp = curr->data;
		curr = curr->left;
	}
	return tmp;
}

template<typename T>
inline T BinaryTree<T>::getMax()
{
	node* curr = root;
	T tmp = curr->data;
	while (curr) {
		tmp = curr->data;
		curr = curr->right;
	}
	return tmp;
}

template<typename T>
inline size_t BinaryTree<T>::getSize()
{
	return size;
}

template<typename T>
inline bool BinaryTree<T>::deleteValue(const T value)
{
	if (find(value)) {
		if (root->data == value) {
			freeTree(root);
			return true;
		}
		node* curr = root;
		while (curr) {
			if (value < curr->data) curr = curr->left;
				else
					curr = curr->right;		//if (d > curr->data)	// d!=curr->data
			if (curr->data == value)break;
		}
		
		if (deletecurr(curr, value)) return true;
		return false;
	}
	else
		return false;
}