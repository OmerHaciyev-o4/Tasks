#include <iostream>
#include <set>
using namespace std;

template<class T>
class BinaryMyNode
{
	T value{};
	BinaryMyNode<T>* parent{};
	BinaryMyNode<T>* left{};
	BinaryMyNode<T>* right{};
	template<class U>
	friend class Set;
public:
	BinaryMyNode(T _value) : value(_value) { }
};

template<class T>
class Set
{
	BinaryMyNode<T>* root{};
	void search(BinaryMyNode<T>* temp, BinaryMyNode<T>* node, BinaryMyNode<T>* nodeP)
	{
		if (node->value > temp->value)
		{
			BinaryMyNode<T>* temp1 = new BinaryMyNode<T>(temp->value);
			temp->parent = temp1;
			if (temp->right == NULL)
			{
				temp->right = node;
				temp->right->left = NULL;
				temp->right->right = NULL;
			}
			else
			{
				temp = temp->right;
				search(temp, node, nodeP);
			}
		}
		else if (node->value < temp->value)
		{
			BinaryMyNode<T>* temp1 = new BinaryMyNode<T>(temp->value);
			temp->parent = temp1;
			if (temp->left == NULL)
			{
				temp->left = node;
				temp->left->right = NULL;
				temp->left->left = NULL;
			}
			else
			{
				temp = temp->left;
				search(temp, node, nodeP);
			}
		}
	}
	void fSearch(const T& num, BinaryMyNode<T>* count, BinaryMyNode<T> address)
	{
		if (num == count->value)
		{
			address.value = count->value;
		}
		else if (num > count->value)
		{
			count = count->right;
			fSearch(num, count, address);
		}
		else if (num < count->value)
		{
			count = count->left;
			fSearch(num, count, address);
		}
	}
	void allClear(BinaryMyNode<T>* temp)
	{
		allClear(temp->left);
		allClear(temp->right);
		delete temp;
	}
	void searchBigelement(BinaryMyNode<T>* prev, BinaryMyNode<T>* current, BinaryMyNode<T>* prevValue, T& value)
	{
		if (current != NULL)
		{
			prevValue = prev;
			prev = current;
			current = current->left;
			if (current != NULL)
			{
				prevValue = prev;
				prev = current;
				current = current->left;
				searchBigelement(prev, current, prevValue, value);
			}
			else
			{
				value = prev->value;
				delete prev;
				prev = NULL;
				prevValue->left = NULL;
			}
		}
		else
		{
			value = prev->value;
			delete prev;
			prev = NULL;
			prevValue->left = NULL;
		}
	}
	void deleteElement(BinaryMyNode<T>* prev, BinaryMyNode<T>* current, T& value,const T& num)
	{
		if (num == current->value)
		{
			BinaryMyNode<T>* temp = NULL;
			BinaryMyNode<T>* temp1 = NULL;
			BinaryMyNode<T>* prevValue = current;
			temp = current;
			prev = prev->right;
			temp1 = prev;
			prev = current;
			current = current->right;
			searchBigelement(prev, current, prevValue, value);
			current = temp;
			prev = temp1;
			current->value = value;
			current->parent = prev;
		}
		else if (num < current->value)
		{
			current = current->left;
			deleteElement(prev, current, value, num);
		}
		else if (num > current->value)
		{
			current = current->right;
			deleteElement(prev, current, value, num);
		}
	}
public:
	void insert(const T& val)
	{
		BinaryMyNode<T>* myNode = new BinaryMyNode<T>(val);
		BinaryMyNode<T>* temp = root;
		BinaryMyNode<T>* parent = root;
		if (root == NULL)
		{
			root = myNode;
		}
		else search(temp, myNode, parent);
	}
	T* find(const T& num)
	{
		BinaryMyNode<T>* count = root;
		BinaryMyNode<T> address = NULL;
		fSearch(num, count, address);
		return &(address.value);
	}
	void clear()
	{
		BinaryMyNode<T>* temp = root;
		if (temp == NULL) { return; }
		else
		{
			allClear(temp);
		}
	}
	void erase(const T& val)
	{
		T value{};
		BinaryMyNode<T>* prev = root;
		BinaryMyNode<T>* current = root;
		if (root == NULL) { return; }
		else
		{
			deleteElement(prev, current, value, val);
		}
	}
	
	void printTree()
	{
		if (root == NULL) return;
		printMain(root);
	}
	void printMain(BinaryMyNode<T>* root)
	{
		if (root == NULL) return;
		else if (root->value != NULL)
		{
			cout << root->value << endl;
		}
		if (root->left != NULL)   printMain(root->left);
		if (root->right != NULL) printMain(root->right);
	}

};

int main()
{
	Set<int> i;
	i.insert(50);
	i.insert(55);
	i.insert(35);
	i.insert(37);
	i.insert(60);
	i.insert(54);
	i.insert(58);
	i.insert(56);
	i.printTree();
	cout << endl << endl;
	i.erase(55);
	i.printTree();
	cout << endl << endl;
	cout << i.find(37);
	i.clear();
	i.printTree();

}