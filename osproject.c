#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 10

int queues[size], queuet[size];
void s_process();
void t_process();
void dels();
void delt();
void s_insert(int);
void t_insert(int);
int fronts=-1,rears=-1,frontt=-1,reart=-1;
int preemption;

void s_insert(int vals)
{
	if((fronts==0 && rears==size-1) || fronts==rears+1)
 	 {
  		printf("student queue is full:insertion not possible"); 
 	 }
 	 
	else
	{
		if(fronts==-1 && rears==-1)
		{
  		fronts=0;
  		rears=0;
  		}
  		
  		else if(rears==size-1)
  		{
  		rears=0;	
		}
		else
		rears=rears+1;
		
		queues[rears]=vals;
		printf("\nstudent %d is inserted",vals);
	}
}

void t_insert(int valt)
{
	if(frontt==0 && reart==size-1 || frontt==reart+1)
 	 {
  		printf("teacher queue is full:insertion not possible"); 
 	 }
 	 
	else
	{
		if(frontt==-1 && reart==-1)
		{
  		frontt=0;
  		reart=0;
  		}
  		
  		else if(reart==size-1)
  		{
  		reart=0;	
		}
		else
		reart=reart+1;
		
		queuet[reart]=valt;
		printf("\nteacher %d is inserted",valt);
	}
}

void dels()
{
	if(fronts==-1 && rears==-1)
	{
	printf("\nno student in queue to process!");
	return;
	}
	
	if(fronts==rears)
	{
	printf("\nProcessed student: %d\n", queues[fronts]);
	fronts=-1;
	rears=-1;
	}
	else if(fronts==size-1)
	{
	printf("\nProcessed student: %d\n", queues[fronts]);
	fronts=0;
	}
	
	else
	{
	printf("\nProcessed student: %d\n", queues[fronts]);
	fronts++;
	}
	
	
}

void delt()
{
	if(frontt==-1 && reart==-1)
	{
	printf("\nno teacher in queue to process!");
	return;
	}
	
	if(frontt==reart)
	{
	printf("\nProcessed teacher: %d", queuet[frontt]);
	frontt=-1;
	reart=-1;
	}
	else if(frontt==size-1)
	{
	printf("\nProcessed teacher: %d", queuet[frontt]);
	frontt=0;
	}
	
	else
	{
	printf("\nProcessed teacher: %d", queuet[frontt]);
	frontt++;
	}
	
}

void process(){
	int ch;
   if(reart == -1)
   {
   	
      printf("\nno teacher in queue to process!");
   
  	 if(rears==-1)
  	 printf("\nno student to process!");
   while(fronts!=-1)
	{
    
    dels();
    if(1)
    {
    printf("\ninsert teacher ?\n1.Yes\n2.No\n");
      scanf("%d",&ch);
      if(ch ==1)
      {
      	preemption=1;
      	return;
	  }
	}
    sleep(1);
	}
   }
   else{
      while(frontt!=-1)
	{  
      
      delt();
      sleep(1);
	}
	if(rears==-1)
	
   	printf("\nno student to process!");
   	
	while(fronts!=-1)
	{
      dels();
      if(1){
      printf("\ninsert teacher ?\n1.Yes\n2.No\n");
	  scanf("%d",&ch);
      if(ch==1)
      {
      	preemption=1;
      	return;
	  }
	  sleep(1);
	}
	}
   }
}


int main()
{
	int d,n,i;
	preemption=0;
	while(1)
	{
	if(preemption==1)
	{
	d=2;
	goto k;
	}
	printf("\n\nenter your choice :-");
	printf("\n 1. insert students");
	printf("\n 2. insert teachers");
	printf("\n 3. process student and teacher on library counter.\n");
	printf("\n- ");
	scanf("%d",&d);
	k:
	switch(d)
	{
		case 0:
			exit(0);
			
		case 1:
			printf("\nenter no. of students-");
			scanf("%d",&n);
			for(i=1;i<=n;i++)
			{
				s_insert(i);
				sleep(1);
			}
			break;
		
		case 2:
			printf("\nenter no. of teachers-");
			scanf("%d",&n);
			for(i=1;i<=n;i++)
			{
				t_insert(i);
				sleep(1);
			}
			preemption=0;
			break; 
			
		case 3:
			process();
			break;
	
		default:
			printf("invalid choice");
			break;
	}
	}
	return 0;
}
