#include <stdio.h>
#define bool int
 
	 // Time complexity of Merge Sort is  O(nLogn) in all 3 cases (worst, average and best) as merge sort always divides the array into two halves and takes linear time to merge two halves.
	// Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.
	
	
	
	
	
	// Merges two subarrays of arr[].
	// First subarray is arr[l..m]
	// Second subarray is arr[m+1..r]
	
	
	
	void merge(int sequence[], int left, int middle, int right)
	{
	    int i, j, k;
	    int number1 = middle - left + 1;
	    int number2 = right- middle;
	  
	    /* create temp arrays */
	    int LtempArray[number1], RtempArray[number2];
	  
	    /* Copy data to temp arrays L[] and R[] */
	    for (i = 0; i < number1; i++)
		LtempArray[i] = sequence[left + i];
	    for (j = 0; j < number2; j++)
		RtempArray[j] = sequence[middle + 1 + j];
	  
	    /* Merge the temp arrays back into arr[l..r]*/
	    i = 0; // Initial index of first subarray
	    j = 0; // Initial index of second subarray
	    k = left; // Initial index of merged subarray
	    while (i < number1 && j < number2) {
		if (LtempArray[i] <= RtempArray[j]) {
		    sequence[k] = LtempArray[i];
		    i++;
		}
		else {
		    sequence[k] = RtempArray[j];
		    j++;
		}
		k++;
	    }
	  
	    /* Copy the remaining elements of L[], if there
	    are any */
	    while (i < number1) {
		sequence[k] = LtempArray[i];
		i++;
		k++;
	    }
	  
	    /* Copy the remaining elements of R[], if there
	    are any */
	    while (j < number2) {
		sequence[k] = RtempArray[j];
		j++;
		k++;
	    }
	}
	  
	  
	  
	  
	  
	  
	  
	/* l is for left index and r is right index of the
	sub-array of arr to be sorted */
	void mergeSort(int array[], int left, int right)
	{
	    if (left < right) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int middle = left + (right - left) / 2;
	  
		// Sort first and second halves
		mergeSort(array, left, middle);
		mergeSort(array, middle + 1, right);
	  
		merge(array, left, middle, right);
	    }
	}
	  
	  
	bool hasArrayTwoCandidates(
	    int Array[], int size, int sum)
	{
	    int l, r;
	 
	    /* Sort the elements */
	    mergeSort(Array, 0, size - 1);
	 
	    /* Now look for the two candidates in the sorted
	       array*/
	    l = 0;
	    r = size - 1;
	    while (l < r) {
		if (Array[l] + Array[r] == sum)
		    return 1;
		else if (Array[l] + Array[r] < sum)
		    l++;
		else // A[i] + A[j] > sum
		    r--;
	    }
	    return 0;
	}
	 
	 
	 
	 
	void exchange(int* a, int* b)
	{
	    int temp;
	    temp = *a;
	    *a = *b;
	    *b = temp;
	}
	 
	 
	 
	 
	int partition(int Array[], int si, int ei)
	{
	    int x = Array[ei];
	    int i = (si - 1);
	    int j;
	 
	    for (j = si; j <= ei - 1; j++) {
		if (Array[j] <= x) {
		    i++;
		    exchange(&Array[i], &Array[j]);
		}
	    }
	    exchange(&Array[i + 1], &Array[ei]);
	    return (i + 1);
	}




int main(){



	int sequence[50]={0};
	int elementCount=0,i=0,sum=0;
	scanf("%d",&elementCount);
	//printf("n= %d\n",elementCount);

	int element=0;
	int count=0;


	while(i<elementCount){ //IT COUNTS 0 TO N
		
		scanf("%d",&element);
		//printf("element %d = %d\n",i,element);
		sequence[i]=element;
		
	   ++i; 
	}
	scanf("%d",&sum);
	
	 if (hasArrayTwoCandidates(sequence, i, sum))
	 // Time complexity of Merge Sort is  O(nLogn) in all 3 cases (worst, average and best) as merge sort always divides the array into two halves and takes linear time to merge two halves.
	 //O(N)+O(nLog(n))=O(nLog(n))
		printf("YES");
	    else
		printf("NO");





return 0;
}
