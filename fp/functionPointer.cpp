#include <vector>
#include <iostream>

//#define FP_ENABLE 0
#define LAMBDA 1
#define FP_DIRECT 0
void PrintVal(int val)
{
    std::cout<< " Val:" << val<<std::endl;
}

void HelloWorld()
{
    std::cout<< "Hello World !!" <<std::endl;
}

void ForEach(const std::vector<int> values, void (*fp)(int))
{
    for(auto val: values)
    {
        (*fp)(val);
    }
}

int main()
{
#ifdef FP_ENABLE 
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    ForEach(vec, PrintVal);
#elif FP_DIRECT
    auto fp = HelloWorld;
    fp();
    
    //OR
    typedef (*HelloWorldFunc)();
    HelloWorldFunc instance = HelloWorld;
    instance();
#elif LAMBDA
    std::cout<< "lamda"<<std::endl;
    std::vector<int> values = {1, 2, 3, 4, 5, 6};
    ForEach(values, [](int values) 
    {
        std::cout << " Values "<< values<<std::endl;
    }
    );
#endif
    return 0;
}
