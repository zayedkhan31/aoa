#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void print_arr(char, int *, int, int);

void merge(int *arr, int start, int mid, int end) {
	int size_left = mid - start + 1;
	int size_right = end - mid;
	int i = 0, j=0, k = start, l=0, m=0, n=0;
	int L[size_left], R[size_right];

	for(l=start, m=0; l <= mid, m<size_left; l++, m++) 
		L[m] = arr[l];
	for(l=mid + 1, n=0; l <= end, n<size_right; l++, n++) 
		R[n] = arr[l];


	while(k <= end) {
		if (i < size_left  && j < size_right) {
			if(L[i] < R[j]) {
				arr[k] = L[i];
				i++;
			}
			else {
				arr[k] = R[j];
				j++;
			}
		}
		else if (i >= size_left) {
			arr[k] = R[j];
			j++;
		}
		else if(j >= size_right) {
			arr[k] = L[i];
			i++;
		}
		k++;
	}


}

void merge_sort(int *arr, int start, int end) {
	int mid;
	printf("[Start, End]: %d, %d\n", start, end);
	if (end - start < 1) {
		return;
	}
	mid = (end - start) / 2  + start;
	merge_sort(arr, start, mid);
	merge_sort(arr, mid + 1, end);
	merge(arr, start, mid, end);
}

void print_arr(char type, int *arr, int start, int end) {
	int i;
	printf("%c: ", type);
	for(i = start; i <= end; i++) printf("%d ", arr[i]);
	printf("\n");
}

void main(){
	int arr[SIZE], i;
	for (i = 0; i < SIZE; i++){
		arr[i] =  SIZE - i; /* Decendening */
	}
	print_arr('M', arr, 0, SIZE-1);
	merge_sort(arr, 0, SIZE - 1);
	print_arr('M', arr, 0, SIZE-1);
	
}
