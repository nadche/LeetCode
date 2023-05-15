# LeetCode
solutions to some leetcode challenges
## 49. Group Anagrams
This solution addresses the LeetCode challenge of grouping anagrams. 
The goal is to take a vector of strings and group them into vectors 
based on anagram relationships. The approach used involves iterating
over each string, creating a counter string to keep track of character
counts, and using the counter string as a key in an unordered map.
The strings are then added to the corresponding vector in the map.
Finally, the grouped anagrams are extracted from the map and returned 
as a vector of vectors of strings. 
This solution provides an efficient way to group anagrams together.

## 238. Product of Array Except Self
This solution addresses the LeetCode challenge of finding the product of array except self. The goal is to take an array of integers and calculate a new array where each element is the product of all the elements in the original array except itself. The approach used involves iterating over the array twice. In the first iteration, a prefix product is calculated by storing the product of all previous elements. In the second iteration, a suffix product is calculated by storing the product of all subsequent elements. The final result is obtained by multiplying the prefix and suffix products at each index. This solution provides an efficient way to compute the product of array elements except for the current element.

## 347. Top K Frequent Elements
These solutions address the LeetCode challenge of finding the top k frequent elements in an array. The goal is to determine the k most frequently occurring elements in the given array.
The first solution uses an unordered map to count the frequency of each element in the array. Then, it sorts the elements based on their frequency in descending order. Finally, it returns the top k elements from the sorted list.
The second solution also utilizes an unordered map to count the frequency of each element. It uses a priority queue to maintain a min-heap of the top k frequent elements. As the map is iterated, elements are added to the priority queue, and if the size of the queue exceeds the difference between the total number of elements and k, the least frequent element is removed. The resulting elements in the priority queue are the top k frequent elements.
Both solutions provide different approaches to solve the challenge, with the first one using sorting and the second one using a priority queue. They offer efficient ways to find the k most frequent elements in the given array.

## 33. Search in Rotated Sorted Array
This solution addresses the LeetCode challenge of searching for a target element in a rotated sorted array. The goal is to find the index of the target element in the given array or return -1 if it is not present.
The approach used in this solution is as follows:
1. Initially, the algorithm searches for the pivot point, which is the index where the array is rotated.
2. After finding the pivot point, it performs a modified binary search on the rotated sorted array.
3. The algorithm updates the low and high indices based on the comparison of the middle element with the target.
4. It continues the binary search until the target element is found or the search space is exhausted, returning the index if found or -1 otherwise.
This solution provides an efficient way to search for a target element in a rotated sorted array using a modified binary search algorithm.

## 704. Binary Search
This solution addresses the LeetCode challenge of performing a binary search on a sorted array to find the index of a target element. The goal is to return the index of the target element in the given array or -1 if it is not present.
The approach used in this solution is a standard binary search algorithm:
1. Initialize the left pointer `l` to the start of the array and the right pointer `r` to the end of the array.
2. While `l` is less than or equal to `r`, calculate the middle index `m` using integer division.
3. Compare the target element with the element at index `m`:
   - If the target is less than `nums[m]`, update `r` to be `m - 1` to search in the left half of the array.
   - If the target is greater than `nums[m]`, update `l` to be `m + 1` to search in the right half of the array.
   - If the target is equal to `nums[m]`, return `m` as the index of the target element.
4. If the target element is not found after the while loop, return -1.
This solution provides an efficient way to perform a binary search on a sorted array to find the index of a target element.

