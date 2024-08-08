#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int a = 1;
int b;

int main(void)
{
	pid_t ret;
	printf("fork()+execl() demo.\n");

	ret = fork();

	switch(ret)
	{
		case -1:
			perror("fork() failed...\n");
			break;
		case 0:
			{
				printf("child process...\n");
				char *argv[] = {"ls","-al",NULL};
				execv("/bin/ls",argv);
				printf("我会不会被执行？\n");//不会被执行。
			}
			break;
		default:
			{
				sleep(1);
		//		execl("/bin/ls","ls",NULL);
				printf("Father Process\n");
			}
			break;
	}

	return 0;
}
