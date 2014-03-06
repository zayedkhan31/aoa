#include<stdio.h>
#include<stdlib.h>

int* random_array(int size) {
	int arr[size], i;
	for(i = 0; i < size; i++) {
		arr[i] = size-i;
	}
	return &arr;
}

