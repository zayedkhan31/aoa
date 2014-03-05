Simple O(n^2) Sorting Techniques
================================

These sorting techniques have a huge time complexity and therefore, are only good for smaller size of data set. There are better techniques for large dataset as will be studied in later experiments.


Insertion Sort
--------------

[Source](http://en.wikipedia.org/wiki/Insertion_sort)

![Alt Graphical View of Insertion Sort](http://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)

###Algorithm

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.

Sorting is typically done in-place, by iterating up the array, growing the sorted list behind it. At each array-position, it checks the value there against the largest value in the sorted list (which happens to be next to it, in the previous array-position checked). If larger, it leaves the element in place and moves to the next. If smaller, it finds the correct position within the sorted list, shifts all the larger values up to make a space, and inserts into that correct position.

The resulting array after k iterations has the property where the first k + 1 entries are sorted ("+1" because the first entry is skipped). In each iteration the first remaining entry of the input is removed, and inserted into the result at the correct position, thus extending the result:


![Before](http://upload.wikimedia.org/wikipedia/commons/3/32/Insertionsort-before.png)
Becomes
![After](http://upload.wikimedia.org/wikipedia/commons/d/d9/Insertionsort-after.png)

with each element greater than x copied to the right as it is compared against x.
The most common variant of insertion sort, which operates on arrays, can be described as follows:
> 1. Suppose there exists a function called Insert designed to insert a value into a sorted sequence at the beginning of an array. It operates by beginning at the end of the sequence and shifting each element one place to the right until a suitable position is found for the new element. The function has the side effect of overwriting the value stored immediately after the sorted sequence in the array.
>2. To perform an insertion sort, begin at the left-most element of the array and invoke Insert to insert each element encountered into its correct position. The ordered sequence into which the element is inserted is stored at the beginning of the array in the set of indices already examined. Each insertion overwrites a single value: the value being inserted.


####Psuedo Code

```
for i ← 1 to length(A)
    x ← A[i]
    j ← i
    while j > 0 and A[j-1] > x
        A[j] ← A[j-1]
        j ← j - 1
    A[j] ← x
```

####Analysis

Insertion sort take O(n^2) time for given input n.

Analysis is simple to see. For each element the inner loop checks all the elements before it for lesser elements and shifts to right till it finds the right place to insert the current element. This works as follows.

>Steps:
>
> Total steps is F(N) = 1 + 2 + 3 + 4 + ... + (N - 1)
>
> By the formula
>
> SUM(1 .. N - 1) = (N)*(N-1)/2 
>
> = 1/2 * (N^2 - N) 
>
> ~ O(n^2)



Selection Sort
--------------

[Source](http://en.wikipedia.org/wiki/Selection_sort)

![Alt Graphical View of Insertion Sort](http://upload.wikimedia.org/wikipedia/commons/9/94/Selection-Sort-Animation.gif)


The algorithm divides the input list into two parts:

* the sublist of items already sorted, which is built up from left to right at the front (left) of the list, 

* and the sublist of items remaining to be sorted that occupy the rest of the list. 

Initially, the sorted sublist is empty and the unsorted sublist is the entire input list. The algorithm proceeds by finding the smallest (or largest, depending on sorting order) element in the unsorted sublist, exchanging it with the leftmost unsorted element (putting it in sorted order), and moving the sublist boundaries one element to the right.


Here is an example of this sort algorithm sorting five elements:

> *64* 25 12 22 **11**

> 11 *25* **12** 22 64

> 11 12 *25* **22** 64

> 11 12 22 ***25*** 64

> 11 12 22 25 ***64***

####Psuedo Code

```
for i ← 1 to length(A)
    x ← A[i]
    k ← 0
    min ← 0
    for j ← i  to length(A)
        if(A[k] < A[j])
            min ← A[j]
            k = j 
    temp ← A[i]
    A[i] ← A[k]
    A[k] ← temp
```

####Analysis

Selection sort is not difficult to analyze compared to other sorting algorithms since none of the loops depend on the data in the array. Selecting the lowest element requires scanning all n elements (this takes n − 1 comparisons) and then swapping it into the first position.   
  
Finding the next lowest element requires scanning the remaining n − 1 elements and so on, 
>for (n − 1) + (n − 2) + ... + 2 + 1 = n(n − 1) / 2 ∈ Θ(n2) comparisons (see arithmetic progression). 

Each of these scans requires one swap for n − 1 elements (the final element is already in place).


