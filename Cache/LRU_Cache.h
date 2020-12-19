#include "LRU_Doubly_Linked_List.h"

class LRUCache
{
	int cache_size;
	int cache_capacity;
	unordered_map<int, DNode*> hashMap;
	doubly_linked_list *list;
	public:
		LRUCache(int CacheSize);
		~LRUCache();
		int get(int key);
		void put(int key, int val);
};

