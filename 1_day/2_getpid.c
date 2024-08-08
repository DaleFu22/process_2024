#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	printf("当前进程号为%d\n",getpid());
	printf("当前进程的父进程号为%d\n",getppid());

	while(1);

	return 0;
}
