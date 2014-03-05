Quick Sort
==========

[Source](http://en.wikipedia.org/wiki/Merge_Sort)

Quicksort, or partition-exchange sort, is a sorting algorithm developed by Tony Hoare that, on average, makes O(n log n) comparisons to sort n items. In the worst case, it makes O(n2) comparisons, though this behavior is rare. Quicksort is often faster in practice than other O(n log n) algorithms.

 Additionally, quicksort's sequential and localized memory references work well with a cache. Quicksort is a comparison sort and, in efficient implementations, is not a stable sort. Quicksort can be implemented with an in-place partitioning algorithm, so the entire sort can be done with only O(log n) additional space used by the stack during the recursion.
 

Algorithm
---------

Conceptually, a merge sort works as follows:

1.  Pick an element, called a pivot, from the list.

2.  Reorder the list so that all elements with values less than the pivot come before the pivot, while all elements with values greater than the pivot come after it (equal values can go either way). After this partitioning, the pivot is in its final position. This is called the partition operation.

3.  Recursively apply the above steps to the sub-list of elements with smaller values and separately the sub-list of elements with greater values.

![Alt Graphical View](http://upload.wikimedia.org/wikipedia/commons/6/6a/Sorting_quicksort_anim.gif)

###Pseudo Code

```
 function quicksort(array)
     if length(array) ≤ 1
         return array  // an array of zero or one elements is already sorted
     select and remove a pivot element pivot from 'array'  // see '#Choice of pivot' below
     create empty lists less and greater
     for each x in array
         if x ≤ pivot then append x to less
         else append x to greater
     return concatenate(quicksort(less), list(pivot), quicksort(greater))

```

###Analysis

**Average Case**
Quicksort takes O(n log n) time on average, when the input is a random permutation. Why? For a start, it is not hard to see that the partition operation takes O(n) time.

In the most unbalanced case, each time we perform a partition we divide the list into two sublists of size 0 and n-1 (for example, if all elements of the array are equal). This means each recursive call processes a list of size one less than the previous list. Consequently, we can make n-1 nested calls before we reach a list of size 1. This means that the call tree is a linear chain of n-1 nested calls. The ith call does O(n-i) work to do the partition, and SUM(1..n-1) = O(n^2), so in that case Quicksort takes O(n^2) time. That is the worst case.

In the most balanced case, each time we perform a partition we divide the list into two nearly equal pieces. This means each recursive call processes a list of half the size. Consequently, we can make only Log n nested calls before we reach a list of size 1. This means that the depth of the call tree is Log n.

**Alternative**
An alternative approach is to set up a recurrence relation for the T(n) factor, the time needed to sort a list of size n. In the most unbalanced case, a single Quicksort call involves O(n) work plus two recursive calls on lists of size 0 and n-1, so the recurrence relation is
T(n) = O(n) + T(0) + T(n-1) = O(n) + T(n-1).

This is the same relation as for insertion sort and selection sort, and it solves to worst case T(n) = O(n^2).
In the most balanced case, a single quicksort call involves O(n) work plus two recursive calls on lists of size n/2, so the recurrence relation is
T(n) = O(n) + 2T(n/2).

The master theorem tells us that T(n) = O(n log n).