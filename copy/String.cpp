#include <iostream>
#include <cstring>

#define COUT_PRINT 0
class String
{
    char *m_Data;
    int m_Size;
    public:
        String() = default;
        String(const char *str)
        {
            m_Size = strlen(str) + 1;
            m_Data = new char[m_Size];
            memcpy(m_Data, str, m_Size);
        }

        String(const String &other)
        {
            m_Size = other.m_Size + 1;
            m_Data = new char[m_Size];
            memcpy(m_Data, other.m_Data, m_Size);
            std::cout<< "copied string " << std::endl;
        }
        
        char& operator[](unsigned int index)
        {
            return m_Data[index];
        }

        ~String()
        {
            delete[] m_Data;
        }
        friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

void PrintString(const String &string)
{
    std::cout<< string <<std::endl;
}

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Data;
    return stream;
}

int main()
{
    String str = "ajays";
#if COUT_PRINT
    std::cout<< str << std::endl;
#else
    PrintString(str);
#endif
    String strNew = str;
#if COUT_PRINT
    std::cout<< strNew << std::endl;
    strNew[2] = 'p';
    std::cout<< strNew << std::endl;
#else
    strNew[2] = 'p';
    PrintString(str);
#endif
    return 0;
}
