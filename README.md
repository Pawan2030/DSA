# DSA
![dsa](https://github.com/Pawan2030/DSA/assets/136910101/e8fd67a4-aa31-412b-81c2-aad5edbd9133)

My Leetcode Solutions

# Important Data Structures and Algorithms

This document provides a summary of key Data Structures and Algorithms (DSA) along with their time and space complexities, and common methods to solve them.

## Sorting Algorithms

### Bubble Sort
- **Time Complexity:** O(n^2)
- **Space Complexity:** O(1)
- **Method:** Repeatedly swapping adjacent elements if they are in the wrong order.

### Selection Sort
- **Time Complexity:** O(n^2)
- **Space Complexity:** O(1)
- **Method:** Repeatedly finding the minimum element from the unsorted part and putting it at the beginning.

### Insertion Sort
- **Time Complexity:** O(n^2)
- **Space Complexity:** O(1)
- **Method:** Building a sorted array one element at a time by repeatedly taking the next element and inserting it into its correct position.

### Merge Sort
- **Time Complexity:** O(n log n)
- **Space Complexity:** O(n)
- **Method:** Dividing the array into halves, sorting them, and then merging them back together.

### Quick Sort
- **Time Complexity:** Average O(n log n), Worst O(n^2)
- **Space Complexity:** O(log n)
- **Method:** Selecting a 'pivot' element and partitioning the other elements into those less than and greater than the pivot.

### Heap Sort
- **Time Complexity:** O(n log n)
- **Space Complexity:** O(1)
- **Method:** Building a max heap and then repeatedly removing the largest element from the heap.

### Counting Sort
- **Time Complexity:** O(n + k)
- **Space Complexity:** O(k)
- **Method:** Counting the number of occurrences of each value and then using this information to place each value in the correct position.

### Radix Sort
- **Time Complexity:** O(nk)
- **Space Complexity:** O(n + k)
- **Method:** Sorting the numbers digit by digit, starting from the least significant digit to the most significant digit.

## Searching Algorithms

### Linear Search
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)
- **Method:** Sequentially checking each element of the list until a match is found.

### Binary Search
- **Time Complexity:** O(log n)
- **Space Complexity:** O(1)
- **Method:** Repeatedly dividing the search interval in half and comparing the middle value to the target.

## Hashing

### Hash Table
- **Time Complexity:** Average O(1), Worst O(n)
- **Space Complexity:** O(n)
- **Method:** Using a hash function to compute an index into an array of buckets, from which the desired value can be found.

## Graph Algorithms

### Depth-First Search (DFS)
- **Time Complexity:** O(V + E)
- **Space Complexity:** O(V)
- **Method:** Exploring as far as possible along each branch before backtracking.

### Breadth-First Search (BFS)
- **Time Complexity:** O(V + E)
- **Space Complexity:** O(V)
- **Method:** Exploring all the neighbor nodes at the present depth prior to moving on to nodes at the next depth level.

### Dijkstra’s Algorithm
- **Time Complexity:** O((V + E) log V)
- **Space Complexity:** O(V)
- **Method:** Using a priority queue to repeatedly select the shortest path vertex, updating its neighbors with the shortest known distance.

### Bellman-Ford Algorithm
- **Time Complexity:** O(VE)
- **Space Complexity:** O(V)
- **Method:** Repeatedly relaxing the edges of the graph.

### Floyd-Warshall Algorithm
- **Time Complexity:** O(V^3)
- **Space Complexity:** O(V^2)
- **Method:** Using dynamic programming to compute shortest paths between all pairs of vertices.

## Dynamic Programming

### Fibonacci Sequence
- **Time Complexity:** O(n)
- **Space Complexity:** O(n) or O(1)
- **Method:** Using a memoization table to store previously computed values or iterative method with constant space.

### Knapsack Problem
- **Time Complexity:** O(nW) (where W is the maximum weight)
- **Space Complexity:** O(nW)
- **Method:** Using a table to store solutions to subproblems.

### Longest Common Subsequence (LCS)
- **Time Complexity:** O(nm)
- **Space Complexity:** O(nm)
- **Method:** Using a 2D table to store lengths of longest common subsequence.

## Tree Traversals

### In-order Traversal
- **Time Complexity:** O(n)
- **Space Complexity:** O(h) (where h is the height of the tree)
- **Method:** Recursively visiting the left subtree, the root, and then the right subtree.

### Pre-order Traversal
- **Time Complexity:** O(n)
- **Space Complexity:** O(h)
- **Method:** Recursively visiting the root, the left subtree, and then the right subtree.

### Post-order Traversal
- **Time Complexity:** O(n)
- **Space Complexity:** O(h)
- **Method:** Recursively visiting the left subtree, the right subtree, and then the root.

## String Algorithms

### Knuth-Morris-Pratt (KMP) Algorithm
- **Time Complexity:** O(n + m)
- **Space Complexity:** O(m)
- **Method:** Using a partial match table to skip characters while matching.

### Rabin-Karp Algorithm
- **Time Complexity:** Average O(n + m), Worst O(nm)
- **Space Complexity:** O(1)
- **Method:** Using hashing to find any one of a set of pattern strings in a text.

## Common Data Structures

### Arrays
- **Access Time Complexity:** O(1)
- **Search Time Complexity:** O(n)
- **Insertion Time Complexity:** O(n)
- **Deletion Time Complexity:** O(n)
- **Space Complexity:** O(n)

### Linked Lists
- **Access Time Complexity:** O(n)
- **Search Time Complexity:** O(n)
- **Insertion Time Complexity:** O(1)
- **Deletion Time Complexity:** O(1)
- **Space Complexity:** O(n)

### Stacks
- **Time Complexity for Push/Pop:** O(1)
- **Space Complexity:** O(n)

### Queues
- **Time Complexity for Enqueue/Dequeue:** O(1)
- **Space Complexity:** O(n)

### Binary Search Trees (BST)
- **Average Time Complexity for Search/Insertion/Deletion:** O(log n)
- **Worst Time Complexity for Search/Insertion/Deletion:** O(n)
- **Space Complexity:** O(n)

### Heaps
- **Time Complexity for Insert/Delete Min:** O(log n)
- **Space Complexity:** O(n)

---

### Author -> Pawan Mehta
