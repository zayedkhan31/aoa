#include<stdio.h>
#define SIZE 10000

int counter = 0;

void quicksort(int *x,int first,int last)
{
    int pivot, j, temp, i;
    int mid; 

    counter++;

     if(first<last){
    	mid = first + (last - first) / 2;
    	temp = x[first];
    	x[first] = x[mid];
    	x[mid] = temp;
         pivot = first;
         i = first;
         j = last;

         while(i<j){
	     counter++;
             while(x[i] <= x[pivot] && i < last){
                i++;
	     	counter++;
	     }
             while(x[j]>x[pivot]) {
                j--;
	     	counter++;
 
	     }
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}

int main(){
  int x[SIZE],i;

  for(i = 0; i < SIZE; i++)
	x[i] = i;

  quicksort(x, 0, SIZE-1);

  printf("\n SIZE: %d Counter : %d\n", SIZE, counter);
  return 0;
}


