#include <iostream>
#include <memory>

// g++ -std=c++14 example.cpp -lpthread
// Memory allocation tracking - heap
// Advantage of having our own operator overloading is, it can be tracked how many allocations vs how many dellocations has happened
// to check memory leak
// Valgrind is another tool, but that takes time to be used

struct Object
{
	int a, b, c;
};

struct AllocationMetrices
{
	uint32_t totalMemory = 0;
	uint32_t freeMemory = 0;
	uint32_t TotalMemoryUsage() {return (totalMemory - freeMemory);}
};

static AllocationMetrices s_memoryTracking;

void PrintMemoryUsage()
{
	std::cout<< "Memory Usage "<< s_memoryTracking.TotalMemoryUsage() << " bytes "<< std::endl;
}

void *operator new(size_t size)
{
	s_memoryTracking.totalMemory += size;
	return malloc(size);
}

void operator delete(void *memory, size_t size)
{
	free(memory);
	s_memoryTracking.freeMemory += size;
}

int main()
{
	PrintMemoryUsage();
#define SMART_POINTER 1
#if SMART_POINTER
	{
		std::string str = "ajay";
		std::cout<<"Using smart pointer"<< std::endl;
		std::unique_ptr<Object> up = std::make_unique<Object>();
		PrintMemoryUsage();
	}
#else
	PrintMemoryUsage();
	Object *obj = new Object;
	Object *obj1 = new Object;
	delete obj;
	PrintMemoryUsage();
#endif
	return 0;
}
