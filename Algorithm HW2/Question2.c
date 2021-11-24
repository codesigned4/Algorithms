#include <stdio.h>

int main(){


	//AGORITHM NAME IS SELECTION SORT AND ITS EFFICIENCY IS O(n*n) OR O(2^n)
	
	int count=0,number=0,i=0,j=0,min,hold;  //All asignments are constant 
	int sequence[100];	////All declarations can be considerable as constant
	
	//O(n)
	while(scanf("%d",&number)!=EOF){ //takes all input
		sequence[count]=number; //assignment
		count++;		
	}
	
	//We apply sigma SIGMA(0 to nSIGMA(1 to n-1)1) and result is O(n*2) OR O(n^2)
	for(i=0;i<count;i++){	//counts zero to n
		for(j=i+1;j<count;j++){	//counts 1 to n-1 
			if(sequence[j]<sequence[i]){	//sorting
				hold=sequence[i];    //assignment 
				sequence[i]=sequence[j]; //assignment
				sequence[j]=hold;	//assginment 
			}
		}
	}
	
	//We apply sigma SIGMA(0 to n)1 result is O(n)
	for(i=0;i<count;i++){ //counts zero to n 
		if(i==count-1){
			printf("%d",sequence[i]);
		}
		else{
			printf("%d ",sequence[i]);
		}
	}
	
	//Then O(n)+O(n*n)+O(n)=O(n*n)
	
return 0;
}
