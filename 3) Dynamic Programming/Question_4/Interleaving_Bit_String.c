#include <stdio.h>
#include <stdbool.h>
 
 //finding length of strings
int len(char *str){
	int i;
	for(i=0;str[i]!='\0';i++){}  //counts 0 to n
	
	return i;
}
//O(n^2) + O(n^2) + O(n) = O(n^2) 
//all assignments,scanning elements,declaration,initialization and comparisions can be considerable as constant time 
int checkInterleaving(char* str1,char* str2,char* str3){
	
	int lenA=len(str1),lenB=len(str2),lenC=len(str3),i,j;
	bool dynamicStringInterleaving[lenA+1][lenB+1];
	
	for(i=0;i<lenA+1;i++){             			//counts 0 to n
		for(j=0;j<lenB+1;j++){	  			//counts 0 to n	
			dynamicStringInterleaving[i][j]=false; 	//SIGMA(0 to n SIGMA(0 to n(1))) equals to O(n*n) or O(n^2) 
		}
	}
	if ((lenA + lenB) != lenC)
       		return false;
	
	for(i=0;i<lenA+1;i++){					//counts 0 to n
		for(j=0;j<lenB+1;j++){				//counts 0 to n
								//SIGMA(0 to n SIGMA(0 to n(1))) equals to O(n*n) or O(n^2) 
			if (i==0 && j==0)
			      dynamicStringInterleaving[i][j] = true;
		
			//A is empty
			else if (i==0) {
				if(str2[j-1]==str3[j-1])
				    dynamicStringInterleaving[i][j] = dynamicStringInterleaving[i][j-1];
			}
 
		    	// B is empty
		    	else if (j==0) {
		        	if (str1[i-1] == str3[i-1])
		            		dynamicStringInterleaving[i][j] = dynamicStringInterleaving[i-1][j];
		    	}
		    	
		    	 else if (str1[i-1] == str3[i+j-1] && str2[j-1] != str3[i+j-1])
				
				dynamicStringInterleaving[i][j] = dynamicStringInterleaving[i-1][j];
		 
			    // Current C character matches with current B character,but doesn't match with current A character
			    else if (str1[i-1] != str3[i+j-1] && str2[j-1] == str3[i+j-1])				
				dynamicStringInterleaving[i][j] = dynamicStringInterleaving[i][j - 1];
			    
			    // Current C character matches with that of both A and B
			    else if (str1[i-1] == str3[i+j-1] && str2[j-1] == str3[i+j-1])

				dynamicStringInterleaving[i][j] = (dynamicStringInterleaving[i-1][j] || dynamicStringInterleaving[i][j-1]); 
						
				
		}
	}
	
 	return dynamicStringInterleaving[lenA][lenB];
	
}


void test(char* str1, char* str2, char* str3)
{
    if (checkInterleaving(str1, str2, str3))
        printf("YES");
    else
        printf("NO"); 

}

int main(){

	int i,j,count=0;

	char str1[20]={""},str2[20]={""},str3[20]={""};



	scanf("%s %s %s",str1,str2,str3);



	//O(n^2) + O(n^2) + O(n) = O(n^2) 
	test(str1,str2,str3);



return 0;}
