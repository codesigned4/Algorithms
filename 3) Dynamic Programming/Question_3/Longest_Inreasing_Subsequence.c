#include <stdio.h>
#include <stdlib.h>	


//finding maximum number
int maximum(int number1,int number2){
	return number1>number2?number1:number2;
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
//sorting array
void selectionSort(int array[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
 
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (array[j] < array[min_idx])
                min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        swap(&array[min_idx], &array[i]);
    }
}

//the algorithm efficiency below is O(n^2)+O(n^2)+O(n^2)+O(n)+O(n)=O(n^2) or O(n*n)
//finding LongestIncreasingSubsequence
 int lis(int* array,int* sortedArray,int size){
	
	int i,j; 			  //declarations of variables can considerable as constant BIG-O
	
	char directions[size+1][size+1];    //declaring 2D char array to store the directions
	
	for(i=0;i<size+1;++i){    	           //it will count 0 to n+1
		for(j=0;j<size+1;j++){    	  //it will also count 0 to n+1
			directions[i][j]='0';	  //here assignment can count as constant BIG-O
		}				  //SIGMA(0 to n+1(SIGMA 0 to n+1(1))) equals to O(n*n) or O(n^2)
	}
	
	
	
	int dynamicProgrammingTable[size+1][size+1]; //declaring 2D int array to solve the problem using Dynamic Programming metod
	
	
	for(i=0;i<size+1;i++){				   //it will count 0 to n+1
		for(j=0;j<size+1;j++){   		   //it will also count 0 to n+1	
			dynamicProgrammingTable[i][j]=0;    //here assignment can count as constant BIG-O
		}					   //SIGMA(0 to n+1(SIGMA 0 to n+1(1))) equals to O(n*n) or O(n^2)	
	}
	
	//all of the comparisions below are constant time
 	for(i=0;i<size+1;i++){					 //it will count 0 to n+1
		for(j=0;j<size+1;j++){				 //it will also count 0 to n+1
			if(i==0||j==0){				 //SIGMA(0 to n+1(SIGMA 0 to n+1(1))) equals to O(n*n) or O(n^2) 
				dynamicProgrammingTable[i][j]=0;	 //here assignment can count as constant BIG-O	
			}else if(array[i-1]==sortedArray[j-1]){	 
				dynamicProgrammingTable[i][j]=1+dynamicProgrammingTable[i-1][j-1];
				directions[i][j]='d';

				
			}else{
				dynamicProgrammingTable[i][j]=maximum(dynamicProgrammingTable[i-1][j],dynamicProgrammingTable[i][j-1]);
				if(dynamicProgrammingTable[i-1][j]>=dynamicProgrammingTable[i][j-1]){
					directions[i][j]='u';
				}else{directions[i][j]='l';
				
				}

			}
			
			
		}
		
	}
	
	int lenghtOfLongestIncreasingSubsequence=dynamicProgrammingTable[size][size];
	//all declarations are constant time so big-o is O(1)
	int* elementOfLIS=(int*)malloc(lenghtOfLongestIncreasingSubsequence*sizeof(int));;
	
	
	i=size;
	j=size;
	int indexes=lenghtOfLongestIncreasingSubsequence-1;

	
	//counts until the reaces to starting element which is 0
	//goes by decreasing the "i" and "j" elements with only comparisions so it will count 1 to n and our big-o will be O(n)
	while(1){
		if(directions[i][j]=='0'){
			break;
		}else if(directions[i][j]=='u'){
			--i;
		}else if(directions[i][j]=='l'){
			--j;
		}else if(directions[i][j]=='d'){
			elementOfLIS[indexes--]=sortedArray[j-1];
			--i;
			--j;
			
		}
		
	
	}
	
	

	int len=lenghtOfLongestIncreasingSubsequence,index=0,k=0;
	int count=len-1;
	
    //counts 0 to n so O(n)
    for(i=0;i<lenghtOfLongestIncreasingSubsequence;i++){
	    i==lenghtOfLongestIncreasingSubsequence-1?printf("%d",elementOfLIS[i]):printf("%d ",elementOfLIS[i]);
	    
	    }
    

 	return lenghtOfLongestIncreasingSubsequence; //returning also can be consireable as constant time
 
 }
 
 
 
 
int main()
{

    int size=0,i=0,j=0,element=0,sizeOfLongestIncreasingSubsequence=0; 	
   
    scanf("%d",&size); //getting size of array number we will have 

    int array[100]; //store the elements here so we declare array
    
    int copyOfArray[100]; //it will be sorted array 
    
     
    while(i<size+1){
	     	
     	scanf("%d",&element);
     	array[i]=element;  	//filling array with input
     	copyOfArray[i]=element;  //copy the main array 
		
	i++;
    }		
 
    selectionSort(copyOfArray, size); //sorting array

    lis(array,copyOfArray,size);      //finding Longest Increasing Subsequence			

   

      
    return 0;
}
