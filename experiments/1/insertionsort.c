#include<stdio.h>
#include<stdlib.h>
#define SIZE 100000

void insertion_sort(int *arr, int n){
	int key, i, j;
	for(j = 1; j < n; j++){
		key = arr[j];
		i = j - 1;
		while (i >= 0 && arr[i] > key){
			arr[i+1] = arr[i];
			i--;
		}
		arr[i+1] = key;
	}
	printf("sorted");
}	

void main(){
	int arr[SIZE], i;
	for (i = 0; i < SIZE; i++){
		arr[i] =  i; /* Decendening */
	}
	insertion_sort(arr, SIZE);
} 		
