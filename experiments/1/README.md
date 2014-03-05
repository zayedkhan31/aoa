Simple O(n^2) Sorting Techniques
================================

These sorting techniques have a huge time complexity and therefore, are only good for smaller size of data set. There are better techniques for large dataset as will be studied in later experiments.


Insertion Sort
--------------
[Wikipedia](http://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)

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

Selection Sort
--------------
