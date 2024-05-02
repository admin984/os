//7 B Client
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 27
int main()
{
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
  /*Now read what the server put in the memory*/
  
  for(s=shm;*s!='\0';s++)
  putchar(*s);
  putchar('\n');
  shmdt(s); //detach shared memory
  shmctl(shmid,IPC_RMID,NULL); //destroy shared memory
  exit(0);
}
  

