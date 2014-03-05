Merge Sort
==========

[Source](http://en.wikipedia.org/wiki/Merge_Sort)

Merge sort (also commonly spelled mergesort) is an O(n log n) comparison-based sorting algorithm. Most implementations produce a stable sort, which means that the implementation preserves the input order of equal elements in the sorted output.

Mergesort is a divide and conquer algorithm that was invented by John von Neumann in 1945. A detailed description and analysis of bottom-up mergesort appeared in a report by Goldstine and Neumann as early as 1948.

Algorithm
---------

Conceptually, a merge sort works as follows:

1.  Divide the unsorted list into n sublists, each containing 1 element (a list of 1 element is considered sorted).

2.  Repeatedly merge sublists to produce new sorted sublists until there is only 1 sublist remaining. This will be the sorted list.


![Alt Graphical View](http://upload.wikimedia.org/wikipedia/commons/c/cc/Merge-sort-example-300px.gif)

####Pseudo Code

**Merge Sort**
```
function merge_sort(list m)
    // Base case. A list of zero or one elements is sorted, by definition.
    if length(m) <= 1
        return m

    // Recursive case. First, *divide* the list into equal-sized sublists.
    var list left, right
    var integer middle = length(m) / 2
    for each x in m before middle
         add x to left
    for each x in m after or equal middle
         add x to right

    // Recursively sort both sublists.
    left = merge_sort(left)
    right = merge_sort(right)
    // *Conquer*: merge the now-sorted sublists.
    return merge(left, right)
```

**Merge**
```
function merge(left, right)
    // receive the left and right sublist as arguments.
    // 'result' variable for the merged result of two sublists.
    var list result
    // assign the element of the sublists to 'result' variable until there is no element to merge. 
    while length(left) > 0 or length(right) > 0
        if length(left) > 0 and length(right) > 0
           // compare the first two element, which is the small one, of each two sublists.
            if first(left) <= first(right)
                // the small element is copied to 'result' variable.
                // delete the copied one(a first element) in the sublist.
                append first(left) to result
                left = rest(left)
            else
                // same operation as the above(in the right sublist).
                append first(right) to result
                right = rest(right)
        else if length(left) > 0
            // copy all of remaining elements from the sublist to 'result' variable, 
            // when there is no more element to compare with.
            append first(left) to result
            left = rest(left)
        else if length(right) > 0
            // same operation as the above(in the right sublist).
            append first(right) to result
            right = rest(right)
    end while
    // return the result of the merged sublists(or completed one, finally).
    // the length of the left and right sublists will grow bigger and bigger, after the next call of this function.
    return result
```

####Analysis

In sorting n objects, merge sort has an average and worst-case performance of O(n log n). If the running time of merge sort for a list of length n is T(n), then the recurrence T(n) = 2T(n/2) + n follows from the definition of the algorithm (apply the algorithm to two lists of half the size of the original list, and add the n steps taken to merge the resulting two lists).

The closed form follows from the master theorem.
In the worst case, the number of comparisons merge sort makes is equal to or slightly smaller than
> **(n ⌈lg n⌉ - 2⌈lg n⌉ + 1)**, 
>which is between **(n lg n - n + 1)** and **(n lg n + n + O(lg n))**.

For merge sort *best case* and *worst case* analysis is one and the same.