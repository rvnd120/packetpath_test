//The function should return the length of data which is between two y's.
//Example: y=0xe, arrray = { 0x1,x2,0xe,0x2,0x3,0x4,0xe). Return 3.
//Return -1 if the pattern is not found;

#include <stdio.h>
int find(char* a, int len, char y)
{
        int i;
	int count = 0;
	for (i = 0; i < len; i++)
	{
		if (a[i] == y) {
			count++;
			break;
		}
	}

	if (count == 0 || i == len) 
	{
		return -1;
	}

	count = 0;
	
	for (i = i+1; i < len; i++)
	{
		if (a[i] == y)
		{
			break;
		}
		else
		{
			count++;
		}
	}
	if (i == len && a[i] != y)
	{
		printf("There is no end y i.e not bounded another y\n");
		return -1;
	}
	return count;
 }


int main(void)
{
    int pos = -1;
    printf("In Main1\n");
    int bet = 0;
	//char array[7] = { 0x1, 0x2,0xe,0x2,0x3,0x4,0x5};
	char array[7] = { 0x1, 0x2,0xe,0xe};
    bet = find(array,7,0xe);
    printf("bet=%d\n", bet);

    return 0;
}
