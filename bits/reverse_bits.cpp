#include <stdio.h>
unsigned char reverse_bits(unsigned char c)
{
	unsigned char res = 0;
	unsigned char tmp = 0;
	unsigned int BITS_SIZE = sizeof(char) * 8;
	for(int i = 0; i<BITS_SIZE; i++) {
		tmp = c & (1 << i);
		if(tmp) 
			res |= 1 << ((BITS_SIZE - 1) - i);
	}
	return res;
}

int main()
{
	unsigned char c = 12;
	printf("%u \n", reverse_bits(c));
	return 0;
}
