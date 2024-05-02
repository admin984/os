//7 B Server
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define MAXSIZE 27
int main()
{
  char c;
  int shmid;
  key_t key;
  char*shm,*s;
    key=5678;
    //get identifier for shared memory
    if((shmid=shmget(key,MAXSIZE,IPC_CREAT |0666))<0)
    {
      perror("shmget");
      exit(1);
    }
    //attach shared memory
    if((shm=shmat(shmid,NULL,0))==(char*)-1)
    {
      perror("shmat");
      exit(1);
    }
  /*Put some things into the memory for the other process to read*/
  s=shm;
  printf("\n Enter data to put in shared memory:");
  while((c=getchar())!='#')
  *s++=c; //detach shared memory
  sleep(2);
  shmdt(s);
  exit(0);
  return 0;
}
  

