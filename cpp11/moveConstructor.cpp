#include <iostream>
#include <cstring>

//move constructor, which has been introduced in c++11 to avoid deep copy when we pass
//object to another object, move constructor is very imp conecpt to avoid the copying 
//of data two times, which happens in c++98 using copy constructor

class String
{
    char *m_Data;
    int m_Size;

    public:
        String() = default;
        String(const char *str)
        {
            std::cout<< "String constructor" <<std::endl;
            m_Size = strlen(str);
            m_Data = new char[m_Size];
            memcpy(m_Data, str, m_Size);
        }
        //copy constuctor
        String(const String &other)
        {
            std::cout<< "String copy constructor" <<std::endl;
            m_Data = new char[other.m_Size];
            memcpy(m_Data, other.m_Data, m_Size);
        }
        ~String()
        {
            delete m_Data;
        }
};

class Entity
{
    char *str;
    public:
    Entity(String(str))
    {

    }
};


int main()
{
    Entity entity("ajay");
	return 0;
}
