#include <stdio.h>

/*
 * Given a byte array(data) of length(len) search for the starting position
 * of 32 bit word 0xDEADBEEF and return the position
 * If it is not found return -1
*/

unsigned char d1[] = { 12,   34,  56,   78, 0xde, 0xad, 0xbe, 0xef, 0, 0 };
unsigned char d2[] = { 12,   34,  56,   78, 0xde, 0xad, 0xbe, 0xe0, 0, 0 };


int search_sync(unsigned char* data, int len)
{
	int i;
	int index = 0;
	//len check 
	if (len < 4)
	{
		printf( "len is less than 4 byte %d\n", len);
		return -1;
	}

	for (i = 0; i < len; i++)
	{
		if (data[i] == 0xDE)
		{
			index = i;
			break;
		}		
	}

	if (i == len)
	{
		printf("not found\n");
		return -1;
	}

	if ((data[i + 1] == 0xAD) && (data[i + 2] == 0xBE) && (data[i + 3] == 0xEF))
	{
		return index;
	}

 
}



int main(void)
{
    int pos = -1;
    printf("In Main1\n");
   

    pos = search_sync(d1, 10);
    printf("pos=%d\n", pos);
    pos = search_sync(d1, 8);
    printf("pos=%d\n", pos);
    pos = search_sync(d2, 10);
    printf("pos=%d\n", pos);

    return 0;
}

