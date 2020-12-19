#include "LRU_Cache.h"
#include <iostream>

LRUCache::LRUCache(int cacheSize)
{
	cache_capacity = cacheSize;
	list = new doubly_linked_list();
	hashMap = unordered_map<int, DNode*>();
}

LRUCache::~LRUCache()
{
	std::unordered_map<int, DNode*>::iterator itr;
	for(itr = hashMap.begin();itr != hashMap.end();itr++)
	{
		delete itr->second;
	}
	delete list;
}

// If key not found, return
// If key found, splice the node
int LRUCache::get(int key)
{
	if(hashMap.find(key) == hashMap.end())
	{
		return -1;
	}
	int val = hashMap[key]->value;
	list->splice_node_to_head(hashMap[key]);
	return val;
}

//Algo. 1. Add to map if key doesn't exist
//	2. if map if full, evict the least accessed node from the list, and the key from hash
void LRUCache::put(int key, int value)
{
	if(hashMap.find(key) != hashMap.end())
	{
		hashMap[key]->value = value;
		list->splice_node_to_head(hashMap[key]);
		return;
	}
	//cache eviction rule applies
	if(this->cache_size == this->cache_capacity)
	{
		int key = list->get_node_from_tail()->key;
		hashMap.erase(key);
		list->erase_node_from_tail();
		this->cache_size--;
	}
	//add node to head
	DNode *node = list->add_node_to_head(key, value);
	this->cache_size++;
	hashMap[key] = node;
}

int main()
{
	LRUCache inst(5);
	cout<< inst.get(1) << endl;
	inst.put(1, 5);
	inst.put(3, 10);
	inst.put(6, 15);
	inst.put(9, 20);
	inst.put(12, 25);
	cout<< inst.get(1) << endl;
	cout<< inst.get(12) << endl;
	inst.put(15, 30);
	cout<< inst.get(15) << endl;
	cout<< inst.get(3) << endl;
	cout<< inst.get(6) << endl;
	cout<< inst.get(11) << endl;
	return 0;
}
