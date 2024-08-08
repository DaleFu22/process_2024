#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int a = 1;
int b = 2;

int main(void)
{
	int c = 3;
	int d = 4;

	printf("演示vfork之后父子进程不会独立分离...\n");

	printf("vfork之前：a = %d\tb = %d\tc = %d\td = %d\n",a,b,c,d);
	pid_t ret = -1;

	ret = vfork();

	switch(ret)
	{
		case -1:
		{
			perror("fork()");
		}
		break;
		case 0:
		{
			a += 2;
			b += 2;
			c += 2;
			d += 2;
			printf("子进程：a = %d\tb = %d\tc = %d\td = %d\n",a,b,c,d);
			exit(1);
		}
		break;
		default:
		{
		//	sleep(1);
			printf("父进程：a = %d\tb = %d\tc = %d\td = %d\n",a,b,c,d);
			exit(1);
		}
	}

	return 0;
}
