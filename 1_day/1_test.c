#include <stdio.h>

int main(void)
{
	int i = 0;
	while(1)
	{
		volatile int j,k;
		for(i = 0;i < 1000000;i++)
		{
			printf("hello %d\n",j++);
			printf("world %d\n",j++);
		}
	}
	return 0;
}
