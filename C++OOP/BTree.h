#pragma once

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

	TVal* getValue(const TKey* key)
	{
		if (key == this->key)
		{
			return &value;
		}
		else if (key < this->key && left != nullptr)
		{
			left->getValue(key);
		}
		else if (key > this->key && right != nullptr)
		{
			right->getValue(key);
		}
		else
		{
			return nullptr;
		}
	}
};



template<class TKey, class TVal>
class BTree
{
	BTreeNode<TKey, TVal>* root = nullptr;

public:
	~BTree();

	void clear();
	void print();

	bool push(const TKey& key, const TVal& val);
	TVal* getValue(const TKey& key);
};

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
				current->left = new BTreeNode<TKey, TVal>(key, val);
				return true;
			}
		}
		else
		{
			return false;
		}
	} while (true)

}

template<class TKey, class TVal>
TVal* BTree<TKey, TVal>::getValue(const TKey& key)
{
	if (root)
	{
		return root->getValue(key);
	}
}
