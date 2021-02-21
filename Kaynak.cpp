#include <iostream>
#include <list>

template<class T>
class Node
{
	T _arr{};
	Node* _next{};

	template<class U>
	friend class LinkedList;
public:
	Node(T arr) : _arr(arr), _next(NULL) { }
};

template<class T>
class LinkedList
{
	Node<T>* head{};
	int count{};

public:
	LinkedList() : head(NULL) { }

	void push_back(const T& val)
	{
		Node<T>* newNode = new Node<T>(val);
		if (head == NULL)
		{
			newNode->_next = NULL;
			head = newNode;
		}
		else
		{
			Node<T>* temp = head;
			while (temp->_next != NULL)
			{
				temp = temp->_next;
			}
			temp->_next = newNode;
			newNode->_next = NULL;
		}
		count++;
	}
	void push_front(const T& val)
	{
		Node<T>* newNode = new Node<T>(val);
		if (head == NULL)
		{
			newNode->_next = NULL;
			head = newNode;
		}
		else
		{
			newNode->_next = head;
			head = newNode;
		}
		count++;
	}
	void pop_back()
	{
		if (count == 0)return;
		else if (count == 1)
		{
			delete head;
			head = NULL;
			count--;
		}
		else
		{
			Node<T>* prev = head;
			Node<T>* current = head->_next;
			while (current->_next != NULL)
			{
				prev = current;
				current = current->_next;
			}
			prev->_next = NULL;
			delete current;
			count--;
		}
	}
	void pop_front()
	{
		if (count == 0) return;
		else if (count == 1)
		{
			delete head;
			head = NULL;
		}
		else
		{
			Node<T>* newHead = head->_next;
			delete head;
			head = newHead;
		}
		count--;
	}
	bool empty()const { return !count; }
	void emplace_back(const T& val) 
	{
		Node<T>* newNode = new Node<T>(val);
		if (head == NULL)
		{
			newNode->_next = NULL;
			head = newNode;
		}
		else
		{
			Node<T>* temp = head;
			while (temp->_next != NULL)
			{
				temp = temp->_next;
			}
			temp->_next = newNode;
			newNode->_next = NULL;
		}
		count++;
	}
	void emplace_front(const T& val)
	{
		Node<T>* newNode = new Node<T>(val);
		if (head == NULL)
		{
			newNode->_next = NULL;
			head = newNode;
		}
		else
		{
			newNode->_next = head;
			head = newNode;
		}
		count++;
	}
	T back()
	{
		if (count == 0)return 0;
		else
		{
			Node<T>* temp = head;
			while (temp->_next != NULL)
			{
				temp = temp->_next;
			}
			return temp->_arr;
		}
	}
	T begin() { return head->_arr; }
	T end() { return back(); }
	T cbegin()const { return begin(); }
	T cend() const { return back(); }
	void clear()
	{
		while (count)
		{
			pop_back();
			count--;
		}
	}
	T& front() { return begin(); }
	void printList()
	{
		Node<T>* temp = head;
		while (temp != NULL)
		{
			std::cout << temp->_arr << std::endl;
			temp = temp->_next;
		}
	}
};

int main()
{
	LinkedList<int> list;
	list.push_back(118);
	list.push_back(102);
	list.push_front(04);
	list.push_front(90);
	list.printList();
	std::cout << "---------------------------------------" << std::endl;
	//-----------------------------------------------
	
	list.pop_front();
	list.pop_back();
	list.printList();
	std::cout << "---------------------------------------" << std::endl ;
	//-----------------------------------------------
	
	std::cout << list.back() << std::endl <<"---------------------------------------"  << std::endl;
	//-----------------------------------------------
	
	std::cout << list.begin() << std::endl <<"---------------------------------------" <<  std::endl;
	//-----------------------------------------------
	
	std::cout << list.cbegin() << std::endl <<"---------------------------------------" <<  std::endl;
	//-----------------------------------------------
	
	std::cout << list.cend() << std::endl <<"---------------------------------------" <<  std::endl;
	//-----------------------------------------------
	
	std::cout << list.empty() << std::endl <<"---------------------------------------" <<  std::endl;
	//-----------------------------------------------
	
	list.clear();
	list.printList();
	std::cout << "All elements have been deleted" << std::endl << "---------------------------------------" << std::endl;
	//-----------------------------------------------
	
	std::cout << list.end() << std::endl << "---------------------------------------" << std::endl;

}