#pragma once
#include <iostream>
#include <fstream>

using namespace std;
template<class TKey, class TVal>
struct BTreeNode
{
	TKey key;
	TVal value;
	BTreeNode* left;
	BTreeNode* right;

	BTreeNode(const TKey& key, const TVal& val) : key(key), value(val), left(nullptr), right(nullptr) {}

	void print()
	{
		if (left != nullptr)
		{
			left->print();
		}
		cout << value << " ";
		if (right != nullptr)
		{
			right->print();
		}
	}

	void del()
	{
		if (left != nullptr)
		{
			left->del();
		}
		if (right != nullptr)
		{
			right->del();
		}
		delete this;
	}

	TVal* getValue(const TKey& key)
	{
		if (key == this->key)
		{
			return &value;
		}
		else if (key < this->key and left != nullptr)
		{
			return left->getValue(key);
		}
		else if (key > this->key and right != nullptr)
		{
			return right->getValue(key);
		}
		return nullptr;
	}

	void for_each(void (*action)(TVal&))
	{
		if (left != nullptr)
		{
			left->for_each(action);
		}
		action(value);
		if (right != nullptr)
		{
			right->for_each(action);
		}
	}

	void for_each(const TKey& number1, const TKey& number2, void (*action)(TVal&))
	{
		if (key > number1 and left != nullptr)
		{
			left->for_each(number1, number2, action);
		}
		if (key >= number1 and key <= number2)
		{
			action(value);
		}
		if (key < number2 and right != nullptr)
		{
			right->for_each(number1, number2, action);
		}
	}

	void for_each(void (*action)(TVal&, ofstream&), ofstream& out)
	{
		if (left != nullptr)
		{
			left->for_each(action, out);
		}
		action(value, out);
		if (right != nullptr)
		{
			right->for_each(action, out);
		}
	}
};



template<class TKey, class TVal>
class BTree
{
	bool isPush;

	BTreeNode<TKey, TVal>* root = nullptr;

	BTreeNode<TKey, TVal>* push_r(const TKey& key, const TVal& val, BTreeNode<TKey, TVal>*& node);

public:
	~BTree();

	void clear();
	void print();

	bool push(const TKey& key, const TVal& val);
	bool push_r(const TKey& key, const TVal& val);
	TVal* getValue(const TKey& key);

	void for_each(void (*action)(TVal&));

	void for_each(const TKey& number1, const TKey& number2, void (*action)(TVal&));
	void for_each(void (*action)(TVal&, ofstream&), ofstream& out);
};

template<class TKey, class TVal>
BTreeNode<TKey, TVal>* BTree<TKey, TVal>::push_r(const TKey& key, const TVal& val, BTreeNode<TKey, TVal>*& node)
{
	if (!node)
	{
		node = new BTreeNode<TKey, TVal>(key, val);
		isPush = true;
		return node;
	}
	if (key == node->key)
	{
		isPush = false;
	}
	else if (key < node->key)
	{
		node->left = push_r(key, val, node->left);
	}
	else if (key > node->key)
	{
		node->right = push_r(key, val, node->right);
	}
	return node;
}

template<class TKey, class TVal>
BTree<TKey, TVal>::~BTree()
{
	if (root)
	{
		clear();
	}
}

template<class TKey, class TVal>
void BTree<TKey, TVal>::clear()
{
	if (root)
	{
		root->del();
	}
	root = nullptr;
}

template<class TKey, class TVal>
void BTree<TKey, TVal>::print()
{
	if (root)
	{
		root->print();
	}
}

template<class TKey, class TVal>
bool BTree<TKey, TVal>::push(const TKey& key, const TVal& val)
{
	if (!root)
	{
		root = new BTreeNode<TKey, TVal>(key, val);
		return true;
	}
	BTreeNode<TKey, TVal>* current = root;
	do
	{
		if (key < current->key)
		{
			if (current->left != nullptr)
			{
				current = current->left;
			}
			else
			{
				current->left = new BTreeNode<TKey, TVal>(key, val);
				return true;
			}
		}
		else if (key > current->key)
		{
			if (current->right != nullptr)
			{
				current = current->right;
			}
			else
			{
				current->right = new BTreeNode<TKey, TVal>(key, val);
				return true;
			}
		}
		else
		{
			return false;
		}
	} while (true);

}

template<class TKey, class TVal>
bool BTree<TKey, TVal>::push_r(const TKey& key, const TVal& val)
{
	push_r(key, val, root);
	return isPush;
}

template<class TKey, class TVal>
TVal* BTree<TKey, TVal>::getValue(const TKey& key)
{
	if (root)
	{
		return root->getValue(key);
	}
	return nullptr;
}

template<class TKey, class TVal>
void BTree<TKey, TVal>::for_each(void (*action)(TVal&))
{
	if (root != nullptr)
	{
		root->for_each(action);
	}
}

template<class TKey, class TVal>
void BTree<TKey, TVal>::for_each(const TKey& number1, const TKey& number2, void (*action)(TVal&))
{
	if (root != nullptr)
	{
		root->for_each(number1, number2, action);
	}
}

template<class TKey, class TVal>
void BTree<TKey, TVal>::for_each(void (*action)(TVal&, ofstream&), ofstream& out)
{
	if (root != nullptr)
	{
		root->for_each(action, out);
	}
}