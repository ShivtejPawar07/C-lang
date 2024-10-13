#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void childprocess();
void parentprocess();
int main()
{
pid_t pid;
pid=fork();
if(pid==0)
childprocess();
else
parentprocess();
return 0;
}
void childprocess(){
printf("chid process id%d",getpid());
  printf("\nI am child process\n");
 
}
void parentprocess()
{
printf("parent process id%d",getpid());
 printf("\nI am parent process\n");
}
