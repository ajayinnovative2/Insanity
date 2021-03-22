#include <iostream>

struct Object
{
    float a, b, c;
};

int main()
{

    uint32_t m_Data[5];//stack
    //heap
    uint32_t *ptr = new uint32_t[5];
    Object *m_Data = new Object();
    return 0;
}
