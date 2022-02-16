#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	~Node();
};

class List
{
public:
	Node *root;
	int size;
	void show();
	void append(int);
	void insert(int, int);
	void remove(int);
};

Node::~Node()
{
	cout << data << " was deleted.\n";
}

void List::insert(int d, int idx)
{
	Node *n = new Node;
	n->data = d;

	if (idx == 0)
	{
		n->next = root;
		root = n;
		return;
	}
	Node *current = root;
	for (int i = 0; i < idx - 1; i++)
	{
		current = current->next;
	}
	n->next = current->next;
	current->next = n;
}

void List::show()
{
	Node *current = root;
	cout << current->data << " ";
	while (current->next)
	{
		current = current->next;
		cout << current->data << " ";
	}
}

void List::append(int d)
{
	Node *n = new Node;
	n->data = d;
	n->next = NULL;
	if (root == NULL)
		root = n;
	else
	{
		Node *current = root;
		while (current->next)
		{
			current = current->next;
		}
		current->next = n;
	}
	size++;
}

// Write List::remove() here 0 14 4 45 20 13
void List::remove(int loc)
{
	Node *current = root;
	Node *p = NULL;
	if (loc == 0)
		root = current->next;
	else{
		for (int i = 0; i < loc; i++)
		{
			if (i == loc - 1)
				p = current;
			current = current->next;
		}
		p->next = current->next;
	}
	delete current;
}
