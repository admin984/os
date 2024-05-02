

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
pid_t cpid;
if(fork()==0)
{
 //child
 printf("\n Current process id is %d",getpid());
 exit(0);
}
else
{
 cpid=sleep(3);
 printf("\n Hello Good Morning");
}
printf("\n Current process id is %d",getpid());
printf("\n Child id is %d",cpid);
}

