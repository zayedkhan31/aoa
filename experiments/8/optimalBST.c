#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int optCost(int freq[], int i, int j)
{
    int r, cost;
   // Base cases
   if (j < i)      // If there are no elements in this subarray
     return 0;
   if (j == i)     // If there is one element in this subarray
     return freq[i];
 
   // Get sum of freq[i], freq[i+1], ... freq[j]
   int fsum = sum(freq, i, j);
 
   // Initialize minimum value
   int min = INT_MAX;
 
   // One by one consider all elements as root and recursively find cost
   // of the BST, compare the cost with min and update min if needed
   for (r = i; r <= j; ++r)
   {
       cost = optCost(freq, i, r-1) + optCost(freq, r+1, j);
       if (cost < min)
          min = cost;
   }
 
   // Return minimum value
   return min + fsum;
}
 
// A utility function to get sum of array elements freq[i] to freq[j]
int sum(int freq[], int i, int j)
{
    int s = 0, k;
    for (k = i; k <=j; k++)
       s += freq[k];
    return s;
}

int optCost_dynamic(int freq[], int size) {

    int i, j, L, r, c;
    int cost[size][size];
    int min = INT_MAX;
    
    for(i = 0; i < size; i++) {
        cost[i][i] = freq[i];
    }
    for(L = 2; L <= size; L++) {
        for(i = 0; i <= (size - L + 1); i++) {
            j = i + L - 1;
            cost[i][j] = INT_MAX; 
            for(r = i; r <= j; r++) {
                c = ((r > i)? cost[i][r - 1]: 0) + ((r < j)? cost[r + 1][j]: 0) + sum(freq, i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }
    return cost[0][size - 1];
}


 
// Driver program to test above functions
int main()
{
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys)/sizeof(keys[0]);
    int cost = optCost(freq, 0, n - 1);
    printf("Cost of Optimal BST is %d\n", cost);
    printf("Cost of Optimal BST is %d\n", optCost_dynamic(freq, n));
    return 0;
}
