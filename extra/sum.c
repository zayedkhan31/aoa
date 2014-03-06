#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int sum(int arr[], int n){
	int i;
	long sum = 0;
	for(i = 0; i < n; i++){
		sum += arr[i];
	}
	return (int) sum;
}

void main(){
	int arr[SIZE], i;
	for(i = 0; i<SIZE;i++){
		arr[i] = SIZE - i;
	}
	printf(" sum : %d\n", sum(arr, SIZE));
}
