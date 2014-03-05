Binary Search Tree
==================

[Source](http://en.wikipedia.org/wiki/Binary_search_tree)

In computer science, a binary search tree (BST), sometimes also called an ordered or sorted binary tree, is a node-based binary tree data structure which has the following properties:

* The left subtree of a node contains only nodes with keys less than the node's key.

* The right subtree of a node contains only nodes with keys greater than the node's key.

* The left and right subtree each must also be a binary search tree.

* There must be no duplicate nodes.


Operations
----------

###Insertion

Insertion operation starts from root node and then recursively searches for the node after which the new node shall be inserted. 

Having reached a place where the node is suppose to be placed and if the location is null, we simply insert the new node

####Psuedo Code

```
def binary_tree_insert(node, key, value):
     if node is None:
         return TreeNode(None, key, value, None)
     if key == node.key:
         return TreeNode(node.left, key, value, node.right)
     if key < node.key:
         return TreeNode(binary_tree_insert(node.left, key, value), node.key, node.value, node.right)
     else:
         return TreeNode(node.left, node.key, node.value, binary_tree_insert(node.right, key, value))

```

####Analysis

Tree height is given by **h = Log(N) ** with *base 2*. 

Everytime we try to insert the node by going to bottom of the list and placing the node in right place. This would take **h** number of recursion.

###Search

Searching is very similar to insertion in that it recursively starts searching from the root node and going down the height of the tree till we find the node we are searching. Otherwise, we return empty.

####Psuedo Code

```
function Find-recursive(key, node):  // call initially with node = root
    if node = Null or node.key = key then
        return node
    else if key < node.key then
        return Find-recursive(key, node.left)
    else
        return Find-recursive(key, node.right)

```

####Analysis

Similar to the insertion, search operation too takes **Log(N)** time for searching the list.

###Delete

There are three possible cases to consider:

*  **Deleting a leaf (node with no children)**: Deleting a leaf is easy, as we can simply remove it from the tree.

*  **Deleting a node with one child**: Remove the node and replace it with its child.

*  **Deleting a node with two children**: Call the node to be deleted N. Do not delete N. Instead, choose either its in-order successor node or its in-order predecessor node, R. Replace the value of N with the value of R, then delete R.


![ALT When both elements exists](http://upload.wikimedia.org/wikipedia/commons/4/46/Binary_search_tree_delete.svg)

####Psuedo Code

```
def find_min(node):   # Gets minimum node (leftmost leaf) in a subtree
    current_node = node
    while current_node.left_child:
        current_node = current_node.left_child
    return current_node
 
def replace_node_in_parent(node, parent, new_value=None):
    if parent:
        if node == parent.left_child:
            parent.left_child = new_value
        else:
            parent.right_child = new_value
    if new_value:
        new_value.parent = node.parent
 
def binary_tree_delete(node, key):
    if key < node.key:
        node.left_child.binary_tree_delete(key)
    elif key > node.key:
        node.right_child.binary_tree_delete(key)
    else: # delete the key here
        if node.left_child and node.right_child: # if both children are present
            successor = node.right_child.find_min()
            node.key = successor.key
            successor.binary_tree_delete(successor.key)
        else if node.left_child:   # if the node has only a *left* child
            node.replace_node_in_parent(self.left_child)
        else if node.right_child:  # if the node has only a *right* child
            node.replace_node_in_parent(self.right_child)
        else: # this node has no children
            node.replace_node_in_parent(None)

```

####Analysis

Considering the list of options available, we must find the node we want to delete. So the analysis works as follows:

> Searching the node to be deleted **Log(N)**
>
>   *  if there is no children or only single node then the deletion takes **O(1)** time. 
>
>   Total time: ** O(Log N) + O(1) **
>    
>   *  if there is both the children then we find previous element which in worst time will take O(Log N) and then O(1) for delete operation.
>
>   Total Time: * O(Log N) + O(Log N) + O(1) = O(2 * Log N + 1)* = **O (Log N) **