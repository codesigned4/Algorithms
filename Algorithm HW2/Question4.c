#include <stdio.h>
#include <stdlib.h>



int main(){
	
	//A brute-force algorithm efficiency below is O(n^2) because of O(n) + O(n^2) + O(n^2) + O(n) =O(n^2)
	
	int task=0,i=0,element=0,j=0,holdDeadline=0,holdId=0,holdProfit=0,date=0;//All assignments can be considerable as constant
	int* sequence; //All declarations can be considerable as constant
	int* printSequence; //declaration
	
	scanf("%d",&task);
	sequence=(int*)malloc(task*3*sizeof(int));
	printSequence=sequence=(int*)malloc(task*3*sizeof(int));
	
	//It counts until it reaches task*3 hence here its efficiency is O(n) 
	while(i<task*3){
		scanf("%d",&element);
		sequence[i]=element;	
		
		i++;
	}
	
	//SIGMA(1 to task*3(SIGMA(4 to task*3)1))=O(n*n) OR O(n^2) 
	for(i=1;i<task*3;i+=3){ //date traversal   It counts one to task*3
		for(j=i+3;j<task*3;j+=3){ //selection for date    //It counts four to task*3 

			
			if((sequence[j])<(sequence[i])){ //check to get max profit  all comparisions can be considerable as constant

				holdId=sequence[j-1]; //assignemnt
				sequence[j-1]=sequence[i-1]; //assignemnt
				sequence[i-1]=holdId; //assignemnt
				
				holdDeadline=sequence[j]; //assignemnt
				sequence[j]=sequence[i]; //assignemnt
				sequence[i]=holdDeadline; //assignemnt
				
				holdProfit=sequence[j+1]; //assignemnt
				sequence[j+1]=sequence[i+1]; //assignemnt
				sequence[i+1]=holdProfit; //assignemnt
						
			}else if(sequence[j]==sequence[i]){ //comparision
				if(sequence[j+1]>sequence[i+1]){ //comparision
					holdId=sequence[j-1]; //assignemnt
					sequence[j-1]=sequence[i-1]; //assignemnt
					sequence[i-1]=holdId; //assignemnt
					
					holdDeadline=sequence[j]; //assignemnt
					sequence[j]=sequence[i]; //assignemnt
					sequence[i]=holdDeadline; //assignemnt
					
					holdProfit=sequence[j+1]; //assignemnt
					sequence[j+1]=sequence[i+1]; //assignemnt
					sequence[i+1]=holdProfit; //assignemnt
					
				}
			
			}							
							
		}				
	}	
	
	//SIGMA(1 to task*3(SIGMA(4 to task*3)1))=O(n*n) OR O(n^2) 
	for(i=1;i<task*3;i+=3){//It counts until task*3 occurs
		for(j=i+3;j<task*3;j+=3){ //It counts until task*3 occurs
			if(sequence[i]==sequence[j]){ //comparision
				sequence[j-1]=-1; //comparision
				sequence[j]=-1; //comparision
				sequence[j+1]=-1; //comparision
			}
		}
	}

	//SIGMA(0 to task*3)1=O(n) 
	for(i=0;i<task*3;i+=3){
		if(sequence[i]!=-1){ //comparision
			printf("%d ",sequence[i]); //all prints can be considerable as constant
		}
	}
	
	
	//O(n) + O(n^2) + O(n^2) + O(n) =O(n^2) 
	
return 0;
}








