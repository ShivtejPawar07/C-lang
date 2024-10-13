#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
int pid=fork();
if(pid>0)
{
printf("parent process:");
printf("ID:%d\n\n",getpid());
}
else if(pid==0)
{
printf("child process:");
printf("ID:%d\n\n",getpid());
printf("parent ID:%d\n\n",getppid());
sleep(5);
printf("child process:");
printf("ID:%d\n",getpid());
printf("parent ID:%d\n\n",getppid());
}
else
{
printf("faild to create child process.");
}
return 0;
}

