#include<stdio.h>
#include<stdlib.h>
#define GOOD_SIZE 5 
#define BIN_SIZE 15

// Using Insertion sort currently. Which has O(n^2) time complexity.
// This can be changed to use quick sort with complexity O(n log n)
// However, all the arrays must be sorted in one go. Or use structure to collect the data
void reverse_sort(int n, int *id, int *cost, int *value, float *ratio) { 
    int i, j;
    int _c, _v, _i;
    float key;
	for(j = 1; j < n; j++){
		key = ratio[j];
        _c = cost[j];
        _i = id[j];
        _v = value[j];
		i = j - 1;
		while (i >= 0 && ratio[i] > key){
			ratio[i+1] = ratio[i];
            id[i+1] = id[i];
            cost[i+1] = cost[i];
            value[i+1] = value[i];
			i--;
		}
		ratio[i+1] = key;
        cost[i+1] = _c;
        value[i+1] = _v;
        id[i+1] = _i;
	}
}

void print_all(int n, int *id, int *cost, int *value, float *ratio){
    int i = 0;
    printf("i c v r\n--------\n");
    while(i < n) {
        printf("%d %d %d %f\n", id[i], cost[i], value[i], ratio[i]);
        i++;
    }
}

void knapsack(int *id, int *cost, int *value, float *ratio, int n, int capacity) {
    int i, j;
    int curr_val;
    int used[GOOD_SIZE];
    int fraction[GOOD_SIZE];
    for(i = 0; i < n; i++) {
        ratio[i] = (float) cost[i]/ value[i];
    }
    print_all(n, id, cost, value, ratio);
    reverse_sort(n, id, cost, value, ratio);
    print_all(n, id, cost, value, ratio);
    i = 0;
    j = 0;
    while (capacity > 0 && i < n) {
        curr_val = value[i]; 
        if(curr_val > capacity) {
            curr_val -= (curr_val - capacity);
        }
        used[j] = id[i];
        fraction[j] = curr_val;
        capacity -= curr_val;
        j++;
        i++;
    }
    for(i = 0; i <j; i++) {
        printf("%d %d\n", used[i], fraction[i]);
    }
}



void main() {
    int i;
    int n = GOOD_SIZE;                          /* The number of objects */
    int id[GOOD_SIZE] = {1, 2, 3, 4, 5};
    int cost[GOOD_SIZE] = {12, 1, 2, 1, 4};     /* c[i] is the *COST* of the ith object; i.e. what YOU PAY to take the object */
    int value[GOOD_SIZE] = {4, 2, 2, 1, 10};    /* v[i] is the *VALUE* of the ith object; i.e. what YOU GET for taking the object */
    float ratio[GOOD_SIZE] = {0.0, 0.0, 0.0, 0.0, 0.0};
    int W = BIN_SIZE;                                 /* The maximum weight you can take */
   
    knapsack(id, cost, value, ratio, n, W); 

}
