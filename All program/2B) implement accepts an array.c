
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

void qsrt(int low,int high,int arr[10]);

int main()
{
   int arr[10],arr2[10],i,j,n,low=0,high,piv,ser,x,status;
   printf("\n How many numbers you want to Enter:");
   scanf("%d",&n);
   high=n-1;
   printf("\n Enter Numbers:");
   for(i=0;i<n;i++)
   {
     scanf("%d",&arr[i]);
     arr2[i]=arr[i];
    }
    printf("\n id of the main process %d \n",getpid());
    pid_t cpid;
    status=fork();
    if(status==0)
    {
      //child
      printf("\n Child:Hello From Child!!!");
      piv=arr[0];
      qsrt(low,high,arr);
      printf("\n Child store the number of child process \n Child parent process id= %d\n",getpid());
      
      for(i=0;i<n;i++)
      {
         printf("%d\t",arr[i]);
         
       }
       printf("\n");
       printf("\n Child:Exiting now..");
       exit(1);
       
     }
     else
     {
       //parent
       printf("\n Parent:Hello From Parent....");
       piv=arr2[0];
       qsrt(low,high,arr2);
       printf("\n Parent:Sorted number by Parent Process\n");
       for(i=0;i<n;i++)
       {
         printf("%d\t",arr2[i]);
        }
        
        wait(&status);
        printf("\n Parent:In zombie state....Exiting now\n");
        exit(1);
      }
      return 0;
      }
      
      void qsrt(int low,int high,int arr[10])
      {
          int i=low,j=high,temp,piv=arr[low];
          while(i<j)
          {
             while(arr[i]<=piv)
             i++;
             while(arr[j]>piv)
             j--;
          if(i<j)
          {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
          }
          else
          {
            temp=arr[j];
            arr[j]=piv;
            arr[low]=temp;
            qsrt(low,j,arr);
            qsrt(i,high,arr);
            
            }
          
        }
     }
   
  
       

