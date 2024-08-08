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
#if 0
				waitpid(ret,&status,0);//阻塞等待pid=ret的子进程退出
				printf("得到子进程的退出值为%d\n",status>>8);
				printf("使用宏获取子进程退出值：%d\n",WEXITSTATUS(status));
				if(WIFEXITED(status))
				{
					printf("子进程是正常退出\n");
				}
				if(WIFSIGNALED(status))
				{
					printf("子进程被信号打断\n");
				}
#endif
				while(waitpid(ret,&status,WNOHANG) == 0)//非阻塞模型
				{
					printf("子进程还没有退出\n");
					usleep(100000);//睡眠100ms
				}
			}
	}
}
