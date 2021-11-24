#include <stdio.h>

int main(){

	//A brute-force algorithm efficiency below is O(n*n*n) OR O(n^3) 
	
	char sequence[200]; //All declarations can be considerable as constant
	int i=0,count=0,j=0,middle=0,lower=0,upper=0,k=0,palindrome=0,word=0; //All assignment can consider as constant
	scanf("%s",sequence);

	//O(n) 
	while(sequence[count]!='\0') //takes input untill it encounter '\0' therefore SIGMA(1 to N)1 =O(n)
		++count;	

	
	//O(n*n*n) OR O(n^3)
	for(i=0;i<count;i++){ //counts zero to n 
		for(j=i+1;j<count;j++){ //counts zero to n-1
			if((i+j)%2==1){ //control for even digits
				
				lower=(i+j)/2; //assignment
				upper=(i+j)/2+1; //assignment 
				word=(j-i+1)/2; //half of word length
				
				//while continue until it encounter break hence it is SIGMA(zero to n) and answer is O(n)
				while(1){
					if(sequence[lower]!=sequence[upper]){	//all comparisions can consider as constant
						break;
					}
					
					if(sequence[lower]==sequence[upper]&&((j-i)==1)){ //comparision	 
						palindrome++;
						break;
					}
					
					if(sequence[lower]==sequence[upper]){ //comparision
						
						word--;
						if(word==0){ //comparision
							palindrome++;
							break;
						}
					}	
					
					lower--;
					upper++;

				}			
			
			}else{
				lower=((i+j)/2)-1; //assignment
				upper=((i+j)/2)+1; //assignment
				word=(j-i)/2; //assignment
			
				//while continue until it encounter break hence it is SIGMA(zero to n) and answer is O(n)
				while(1){
					if(sequence[lower]!=sequence[upper]){	//comparision
						break;
					}
					if(sequence[lower]==sequence[upper]){ //comparision
							
						word--;
						if(word==0){ //comparision
							palindrome++;
							break;
						}
					}	
					lower--;
					upper++;

					}				
			}
			
		}		
	}
	
	
	printf("%d",palindrome);
return 0;
}
