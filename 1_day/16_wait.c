#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	printf("演示wait函数\n");

	pid_t ret = -1;

	ret = fork();

	switch(ret)
	{
		case -1:
			{
				perror("fork()");
				exit(1);
			}
			break;
		case 0:
			{
				sleep(1);
				printf("子进程\n");
				exit(8);
			}
			break;
		default:
			{
				printf("父进程\n");
				int status;
				wait(&status);
				printf("得到子进程的退出值为%d\n",status>>8);
			}
	}
}
