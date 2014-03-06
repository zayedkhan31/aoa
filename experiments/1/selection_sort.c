#include<stdio.h>
#include<stdlib.h>
#define SIZE 100000

void selection_sort(int *arr, int n){
	int pos, temp, i, j;
	for(i = 0; i < n; i++){
		pos = i;
		for (j = i+1; j < n; j++){
			if (arr[pos] > arr[j]){
				pos = j;
			}
		}
		if (pos!=i){
			temp = arr[i];
			arr[i] = arr[pos];
			arr[pos] = temp;
		}
	}
	printf("sorted");
}	

void main(){
	int arr[SIZE], i;
	for (i = 0; i < SIZE; i++){
		arr[i] =  i;
	}
	selection_sort(arr, SIZE);
} 		
	

