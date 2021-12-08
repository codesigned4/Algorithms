#include <stdio.h>

//Power calculator
int power(int x, unsigned int y)
{
    if (y == 0)
        return 1;
    else if (y%2 == 0)
        return power(x, y/2)*power(x, y/2);
    else
        return x*power(x, y/2)*power(x, y/2);
}


//Finding all subsets
void allSubset(int array[],int n,int target){
	int count=power(2,n); //All subset counter
	int i=0,j=0,m=0,sum=0,k=0,s=0,controlNewLine=0,allCombinations[4000]={-1},comCounter=0;//Assignment can be considerable as constant	
	int equalSums[4000]; //Declaration can be considerable as constant
	int indexes[4000]={-1},indexCounter=0;//Assignment 
	
	
	//The outer for loop will run 2^n times to print all subset .
	for(i=0;i<count;i++){ //it counts 0 to 2^n
		sum=0; //assignment
		controlNewLine=0;//assignment
		
		for(j=0;j<n;j++){ //counting 0 to n 
			
			if((i&(1<<j))!=0){ //comparasions can be considerable as constant 
				equalSums[m++]=array[j]; //assignment
			}
			
		}

		for(k=0;k<m;k++){ //0 to n
			sum+=equalSums[k]; //assignment
		}

		
		if(sum!=target){ //comparasion
			m=0; //assignment
		}
		
		else if(sum==target){ //comparasion
			indexes[indexCounter++]=comCounter;//start index of target sum
			for(s=0;s<m;s++){   //0 to n

				allCombinations[comCounter++]=equalSums[s]; //comparasion
			         
			}
			indexes[indexCounter++]=comCounter;//finish index of target sum
			controlNewLine++;
		}
	
	}
	
	//My algorithm separates the desired sets, one at the beginning and one at the end.
	for(i=indexes[0];i<indexes[1];i++){ //counts 0 to n
		printf("%d ",allCombinations[i]);
	}
	printf("\n");
	
	for(i=indexes[indexCounter-2];i<indexes[indexCounter-1];i++){ //counts 0 to n
		printf("%d ",allCombinations[i]);
	}
	

	//all of above function efficiency is SIGMA(1 to n)+SIGMA(1 to n)+SIGMA(1 to 2^n)(SIGMA(1 to n)(SIGMA(1 to n)1))=O(n)+O(n)+O(2^n^2)=O(2^n^2) means 2 to n^2 power 	

}







int main()
{
   int array[30];//declaration
   int counter=0,element=0,i=0,sum=0;//assignemnt

   
   while(scanf("%d",&element)!=EOF){//taking input until it encounters EOF hence we can consider as 1 to N
   	array[counter++]=element; //assignment
   }
   for(i=0;i<counter;i++){ //1 to n
   	sum+=array[i];
   }
   
   //Loops above is O(n)+O(n)=O(n)
   //Function which is below is O(2^n^2)
   
   allSubset(array,counter,sum/2);
   
   //Therefore brute-force algorithm which is above efficiency is O(2^n^2)
   
   return 0;
}
