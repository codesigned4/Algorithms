#include <stdio.h> 
#include <stdbool.h>

//IT COUNTS 0 TO SIZE THEREFORE ITS BIG-O IS O(n)
void check(int array[], int size, int sum) 
{ 
  int i, temp; 
  bool hashSet[50] = {0}; /*initialize hash set as 0*/
  int count=0;

  for (i = 0; i < size; i++) //IT COUNTS 0 TO SIZE THEREFORE ITS BIG-O IS O(n)
  { 
      temp = sum - array[i]; 
      if (temp >= 0 && hashSet[temp] == 1){
        printf("YES");
        ++count;
	break;
	
      }
         
        
      hashSet[array[i]] = 1; 
  } 
  

  
 if(count!=1)
  	printf("NO");

} 
  
/* Driver program to test above function */
int main() 
{ 
	int sequence[50]={0};
	int elementCount=0,i=0,sum=0;
	scanf("%d",&elementCount);

	int element=0;
	int count=0;


	while(i<elementCount){	//IT COUNTS 0 TO N
		scanf("%d",&element);

		sequence[i]=element;
		
	   ++i; 
	}
	
	scanf("%d",&sum);
		
	
    int size = sizeof(sequence)/sizeof(sequence[0]); 
  
  //IT COUNTS 0 TO SIZE THEREFORE ITS BIG-O IS O(n)+O(n)=O(n)
    check(sequence,size, sum); 
  


    return 0; 
} 
