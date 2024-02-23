#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define max 5


bool goal(int *);
bool attack(int *,int, int);
void nqueen(int*,int);
main()
 {
	int A[max];
    int i;
	//initialize
	for(i=0;i<max;i++)
	 A[i]=0;
	 	 
	
	printf("\nthe solutions for %d queens",max);
	nqueen(A,0);

 }
 
 void nqueen(int *A,int i)
  {
 	int k;
	 for(int j = 1;j<=max;j++)
 	   {
		 //try to place queen j in position i
		 A[i]=j;
		 
		 for(k=i+1;k<max;k++)  //make all zero after ith position when backtracking
	         A[k] = 0;
		 
		 if(!attack(A,i,j))
 	 	  {
						
			if(i==max-1)
			 {
			 	//check if goal reached
		      if(goal(A))
			   { 
			    printf("\ngoal: \n");
	            for(k=0;k<max;k++)
	            printf(" %d ",A[k]);
	            
	            //exit(0);
	           }
		      }
		      
		    if(i<max-1)
			 nqueen(A,i+1); 
		   }
		}	
 	 	  
	}   
	  
	  
  bool attack(int *A,int i,int j)
  {
  	int k;
	 for(k=0;k<i;k++)
  	   {
  	 	if(A[k]==j||abs(k-i)==abs(A[k]-j))
  	 	 return true;
	   }
    return false;
  }
  
bool goal(int *A)
  {
  	return(!attack(A,max-1,A[max-1]));
  	
  } 