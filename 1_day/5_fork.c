#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	printf("演示fork函数.\n");

	pid_t ret = -1;

	ret = fork();

	if(ret > 0)//父进程会满足条件
	{
		sleep(1);
		printf("我是父进程，我的pid = %d\n",getpid());
		printf("我是父进程，我的子进程pid = %d\n",ret);
	}
	else if(ret == 0)//子进程会满足条件
	{
		printf("我是子进程，我的pid = %d\n",getpid());
		printf("我是子进程，我的父进程pid = %d\n",getppid());
	}
	else
	{
		perror("fork()");
	}

	return 0;
}
