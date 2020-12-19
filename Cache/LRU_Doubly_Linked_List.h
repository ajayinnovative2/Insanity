#include <iostream>
#include <unordered_map>

using namespace std;
//doubly linked list node
class DNode
{
	public:
	int key, value;
	DNode *prev, *next;
	DNode(int key, int value):key(key), value(value), prev(NULL), next(NULL) 
	{
	}
};

//doubly linked list
class doubly_linked_list
{
	DNode *head, *tail;
	public:
	doubly_linked_list(): head(NULL), tail(NULL) {}
	~doubly_linked_list() { }
	bool is_empty()
	{
		return (tail == NULL);
	}
	//erase node from tail
	void erase_node_from_tail()
	{
		if(is_empty())
		{
			return;
		}
		if(head == tail)
		{
			delete tail;
			head = tail = NULL;
		}
		else
		{
			DNode *del = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete del;
		}

	}
	//adding node to the head
	DNode *add_node_to_head(int key, int value)
	{
		DNode *node = new DNode(key, value);
		if(!head && !tail)
		{
			head = tail = node;
		}
		else
		{
			node->next = head;
			head->prev = node;
			head = node;
		}
		return node;
	}

	//move the node to head as and when request for access
	void splice_node_to_head(DNode *node)
	{
		if(node == head)
		{
			return;
		}
		if(node == tail)
		{
			tail->prev->next = NULL;
		}
		else
		{
			if(node->prev) 
			{
				node->prev->next = node->next;
			}
			if(node->next) 
			{
				node->next->prev = node->prev;
			}
		}
		node->next = head;
		head->prev = node;
		node->prev = NULL;
		head = node;
	}

	DNode *get_node_from_tail()
	{
		return tail;
	}
};
