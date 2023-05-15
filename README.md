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

## 74. Search a 2D Matrix
This solution addresses the LeetCode challenge of searching for a target element in a 2D matrix. The goal is to determine whether the target element is present in the matrix and return a boolean value accordingly.
The approach used in this solution is a combination of binary search on the rows and binary search on the columns:
Initialize the top pointer top to the first row and the bottom pointer bot to the last row.
Perform a binary search on the rows by iterating while top is less than or equal to bot:
Calculate the middle row index midRow using the formula top + (bot - top)/2.
Check if the target element is equal to either the first element or the last element of the middle row. If so, return true.
Check if the target element is within the range of the middle row (between the first and last element). If so, break out of the loop.
Update top or bot based on the target element's relationship to the middle row's first and last element.
Initialize the left pointer l to the first column and the right pointer r to the last column.
Perform a binary search on the columns by iterating while l is less than or equal to r:
Calculate the middle column index m using the formula l + (r - l)/2.
Compare the target element with the element at the middle row and middle column index.
Update l or r based on the target element's relationship to the middle column element.
If the target element is found, return true.
If the target element is not found after both binary search loops, return false.
This solution efficiently performs a combination of binary searches on the rows and columns of the matrix to determine whether the target element is present or not.

## 875. Koko Eating Bananas
This solution addresses the LeetCode challenge of finding the minimum eating speed for Koko to eat all the bananas within a given time limit. The goal is to determine the minimum speed at which Koko can eat bananas such that she can finish all the bananas within `h` hours.
The approach used in this solution is a binary search on the range of possible eating speeds:
1. Initialize the `low` variable to 1 (the minimum possible eating speed) and `high` variable to the maximum pile size.
2. Initialize the `result` variable to the maximum pile size as a starting point for the minimum eating speed.
3. Perform a binary search loop while `low` is less than or equal to `high`:
   - Calculate the middle value `k` using the formula `low + (high - low) / 2`.
   - Initialize the `hours` variable to track the total hours needed to eat all the bananas at the current eating speed `k`.
   - Iterate through each pile of bananas and calculate the hours needed to eat that pile by dividing the pile size by the eating speed and rounding up.
   - If the total hours `hours` is less than or equal to the given time limit `h`, update the `result` with the minimum of the current `result` and `k`, and update `high` to `k - 1`.
   - Otherwise, update `low` to `k + 1`.
4. After the binary search loop, return the `result` as the minimum eating speed.
This solution efficiently performs a binary search on the range of possible eating speeds to find the minimum speed at which Koko can eat all the bananas within the given time limit.

## 124. Binary Tree Maximum Path Sum
This solution addresses the LeetCode challenge of finding the maximum path sum in a binary tree. The goal is to determine the maximum sum of any path in the given binary tree.
The approach used in this solution is a recursive Depth First Search (DFS) on the binary tree:
1. Define a helper function `dfs` that takes a `TreeNode*` parameter representing the current node and returns a pair of integers.
2. In the `dfs` function, check if the current node is a leaf node by verifying that both its left and right children are `nullptr`.
   - If it is a leaf node, return a pair of values: the sum of the current node and its children, and the maximum value among the current node and its children.
3. Otherwise, recursively call the `dfs` function on the left and right children of the current node and store the results in variables `left` and `right`, respectively.
4. Calculate the maximum path sum that includes the current node:
   - Compute the maximum path sum among the child paths by selecting the larger value between `left.first` and `right.first`.
   - Compute the new path sum by adding the current node's value, the left child's maximum path sum, and the right child's maximum path sum: `left.second + node->val + right.second`.
5. Return a pair of values: the maximum path sum among the child paths and the maximum path sum that includes the current node.
6. In the `maxPathSum` function, call the `dfs` function on the `root` node and store the result in the `res` variable.
7. Return the maximum value between `res.first` (maximum path sum among the child paths) and `res.second` (maximum path sum that includes the root node).
This solution efficiently performs a DFS on the binary tree to find the maximum path sum by considering various cases (leaf nodes and non-leaf nodes) and updating the maximum path sum accordingly.

## 297. Serialize and Deserialize Binary Tree
This code provides a concise implementation of serializing and deserializing a binary tree using a preorder traversal.
The encode function serializes the tree by traversing it in a preorder manner and appending the node values to an std::ostringstream object. If a node is NULL, it appends the string "N".
The decode function deserializes the encoded string by extracting values from the std::istringstream. If the value is "N", it returns NULL. Otherwise, it creates a new TreeNode with the extracted value and recursively calls decode to set the left and right children.
The serialize function initiates the serialization process by creating an std::ostringstream object and calling encode.
The deserialize function initiates the deserialization process by creating an std::istringstream object with the encoded string and calling decode.
By using a concise implementation of preorder traversal, the code efficiently serializes and deserializes the binary tree.

## 235. Lowest Common Ancestor of a Binary Search Tree
The first solution, lowestCommonAncestor2, is a concise recursive approach to finding the lowest common ancestor of two nodes in a binary search tree. It compares the values of the two nodes with the current root node and recursively calls the function on the left or right subtree accordingly. If the values are on different sides of the root, the root is returned as the lowest common ancestor.
The second solution, lowestCommonAncestor, is a less concise approach that uses a helper function binarySearch to find the path from the root to the given nodes. It stores the paths in two separate vectors. Then, it iterates through the paths and finds the last common node, which represents the lowest common ancestor.

## 102. Binary Tree Level Order Traversal
This solution provides an efficient and concise approach to perform a level order traversal on a binary tree. The goal is to traverse the tree level by level and store the values of each level in separate vectors.
The algorithm uses a queue to keep track of the nodes at each level. It starts by pushing the root node into the queue. Then, in a while loop, it iterates until the queue becomes empty. In each iteration, it retrieves the size of the queue, which represents the number of nodes at the current level.
Within the inner loop, it pops the front node from the queue and adds its value to the current level vector. If the node has left or right child nodes, they are also added to the queue.
After the inner loop finishes, the current level vector is appended to the result vector, which stores all the levels of the binary tree. This process repeats until all levels have been traversed.
Finally, the result vector is returned, containing the values of each level of the binary tree.
This solution has a time complexity of O(n), where n is the number of nodes in the binary tree, as it visits each node once. The space complexity is O(m), where m is the maximum number of nodes at any level, as the queue can store at most m nodes at a time.
To use this solution, simply call the `levelOrder` function and pass the root node of the binary tree as an argument. The function will return a vector of vectors, where each inner vector contains the values of a single level in the binary tree.

## 199. Binary Tree Right Side View
This solution provides an efficient and correct approach to obtain the right side view of a binary tree. The goal is to return a vector containing the values of the nodes that are visible from the right side of the tree.
The first solution, `rightSideView_Wrong`, attempts to traverse the tree by always choosing the right child if it exists. However, this approach is incorrect as it does not consider the possibility of deeper levels on the left side of the tree. Therefore, it provides incorrect results.
The second solution, `rightSideView`, utilizes a level order traversal to ensure that the rightmost node at each level is selected. It uses a queue to keep track of the nodes at each level. The algorithm starts by pushing the root node into the queue. Then, in a while loop, it iterates until the queue becomes empty. In each iteration, it retrieves the size of the queue, which represents the number of nodes at the current level.
Within the inner loop, it pops the front node from the queue and checks if it has a right child or a left child. If a right child exists, it is added to the queue. If a left child exists, it is also added to the queue. Importantly, the right child is pushed before the left child, ensuring that the rightmost node at each level is processed first.
At each level, the algorithm only considers the first node in the queue and adds its value to the result vector. This ensures that only the rightmost node at each level is included in the final result.
Finally, the result vector is returned, containing the values of the rightmost nodes at each level of the binary tree.
This solution has a time complexity of O(n), where n is the number of nodes in the binary tree, as it visits each node once. The space complexity is O(m), where m is the maximum number of nodes at any level, as the queue can store at most m nodes at a time.
To use this solution, simply call the `rightSideView` function and pass the root node of the binary tree as an argument. The function will return a vector containing the values of the rightmost nodes at each level of the binary tree.

## 1448. Count Good Nodes in Binary Tree
This solution provides an efficient approach to count the number of "good" nodes in a binary tree. A good node is defined as a node whose value is greater than or equal to the maximum value encountered along the path from the root to that node.
The algorithm utilizes a depth-first search (DFS) approach to traverse the binary tree. It takes three parameters: the current node, the maximum value encountered so far, and a count variable to keep track of the number of good nodes.
The `dfs` function recursively traverses the binary tree. If the current node is `nullptr`, the function returns. Otherwise, it compares the value of the current node with the maximum value encountered so far. If the current node's value is greater than or equal to the maximum value, it increments the count variable and updates the maximum value to the current node's value.
The `dfs` function is called initially with the root node and the value of the root node as the maximum value. This starts the traversal from the root of the binary tree.
Within the `goodNodes` function, the count variable is initialized to 0. Then, the `dfs` function is called with the root node and the value of the root node as the maximum value. This initiates the traversal of the binary tree. Finally, the count variable is returned as the result, representing the number of good nodes in the binary tree.
This solution has a time complexity of O(n), where n is the number of nodes in the binary tree, as it visits each node once. The space complexity is O(h), where h is the height of the binary tree, as the depth of the recursive function calls depends on the height of the tree.
To use this solution, simply call the `goodNodes` function and pass the root node of the binary tree as an argument. The function will return the count of good nodes in the binary tree.

## 98. Validate Binary Search Tree

This solution aims to validate whether a given binary tree is a valid binary search tree (BST) or not. A BST is a binary tree where the left child of a node is always smaller than the node, and the right child is always larger.
The first solution, `isValidBST_Wrong`, attempts to validate the BST by checking if the left child is smaller than the parent and if the right child is larger. However, this approach is incorrect because it only compares the immediate child nodes with their parent, disregarding the parent of the parent node.
The second solution, `isValidBST`, provides the correct approach. It uses a recursive helper function, `foo`, which takes a node, a lower bound, and an upper bound as parameters. 
Within `foo`, it first checks if the node's value is within the bounds specified by the lower and upper bounds. If it is, the function recursively calls itself on the left and right child nodes, updating the bounds accordingly. This ensures that each node is compared with the correct range of values.
If the node's value is not within the specified bounds or if any of the recursive calls return false, indicating an invalid subtree, the function returns false.
The `isValidBST` function serves as an entry point. It checks if the root is `nullptr` and returns true in that case, indicating an empty tree is a valid BST. Otherwise, it calls the `foo` function with the root node, the smallest possible value as the lower bound, and the largest possible value as the upper bound.
The solution has a time complexity of O(n), where n is the number of nodes in the tree, as it visits each node once. The space complexity is O(h), where h is the height of the tree, as the depth of the recursive function calls depends on the height of the tree.
To use this solution, simply call the `isValidBST` function and pass the root node of the binary tree as an argument. The function will return true if the tree is a valid BST and false otherwise.

## 230. Kth Smallest Element in a BST
This solution aims to find the kth smallest element in a binary search tree (BST). Given a BST, the kth smallest element is the element that appears in the sorted order when all the elements of the BST are placed in ascending order.
The solution uses a recursive helper function, `checkLeft`, which takes a node, a reference to the value of k, and a reference to the current value as parameters. 
Within `checkLeft`, it first checks if the node is `nullptr`. If it is, it returns. Then, it recursively calls `checkLeft` on the left child node, reducing the value of k by 1 for each recursive call. This process effectively traverses the BST in an inorder manner, visiting the left subtree first.
After the left subtree has been visited, the function checks if k has reached 0. If it has, it means that the current node is the kth smallest element. The function updates the value variable with the value of the current node and returns.
If k is not yet 0, the function continues to traverse the right subtree by recursively calling `checkLeft` on the right child node.
The `kthSmallest` function serves as an entry point. It initializes a variable `val` to store the kth smallest element and calls `checkLeft` with the root node, the value of k, and a reference to `val`. After the function call, `val` will contain the kth smallest element.
The solution has a time complexity of O(h + k), where h is the height of the tree and k is the value given as input. The function visits each node in the inorder traversal until it finds the kth smallest element. In the worst case, if k is equal to the number of nodes in the tree, the time complexity becomes O(n). The space complexity is O(h) due to the recursive calls, where h is the height of the tree.
To use this solution, simply call the `kthSmallest` function and pass the root node of the binary tree and the value of k as arguments. The function will return the kth smallest element in the tree.

## 78. Subsets
This solution aims to generate all possible subsets of a given set of integers. Given a set of distinct integers, the solution generates all possible combinations of the elements, including the empty set and the set itself.
The solution uses a recursive helper function, `dfs`, which takes a reference to a vector of vectors called `result`, an integer `start`, a reference to a vector called `l`, and a reference to the input vector of integers called `nums` as parameters.
Within `dfs`, it first pushes the current subset `l` into the `result` vector. This is done to ensure that even the empty set is included in the final result.
Next, it starts a loop from the `start` index until the end of the `nums` vector. For each iteration, it adds the current element at index `i` to the subset `l` and recursively calls `dfs` with an updated `start` index of `i + 1`. This ensures that each element is considered only once and avoids generating duplicate subsets.
After the recursive call, the function removes the last element from the subset `l` using the `pop_back()` function. This is done to backtrack and explore other possibilities in subsequent iterations.
The `subsets` function serves as an entry point. It initializes an empty vector of vectors called `result` to store all the subsets. It also initializes an empty vector called `l` to store the current subset being generated. Then, it calls the `dfs` function with `result`, `0` as the starting index, `l`, and the input `nums` vector. After the function call, `result` will contain all the possible subsets of `nums`.
The solution has a time complexity of O(2^n), where n is the number of elements in the `nums` vector. This is because the solution generates all possible combinations of the elements, which can be represented as a binary string of length n, where each bit indicates whether an element is included or not in the subset. The space complexity is O(n) due to the recursive calls and the space required to store the subsets.
To use this solution, simply call the `subsets` function and pass a vector of integers as the input. The function will return a vector of vectors, where each inner vector represents a subset of the input integers.

## 39. Combination Sum
This solution aims to find all unique combinations of a given set of candidate numbers that sum up to a target value. The solution uses a depth-first search (DFS) approach to generate the combinations.
The solution begins by sorting the `candidates` vector in ascending order. This step is important to ensure that the combinations are generated in non-decreasing order.
The solution defines a recursive helper function called `dfs`, which takes the `candidates` vector, the `target` sum, the current sum `sum`, the `start` index, a vector `l` to store the current combination being generated, and a vector of vectors `result` to store the final combinations.
Within the `dfs` function, it first checks two base cases:
- If the current sum `sum` exceeds the target sum, it immediately returns since going further with the current combination will not result in a valid combination.
- If the current sum `sum` is equal to the target sum, it means a valid combination has been found. The current combination `l` is added to the `result` vector.
Next, it starts a loop from the `start` index until the end of the `candidates` vector. For each iteration, it adds the current candidate number at index `i` to the combination `l` and recursively calls `dfs` with an updated `sum` by adding the current candidate number to it. The `start` index remains the same to allow the possibility of reusing the same number in the combination. After the recursive call, it removes the last element from the combination `l` using the `pop_back()` function to backtrack and explore other possibilities in subsequent iterations.
The `combinationSum` function serves as the entry point. It first sorts the `candidates` vector. Then, it initializes an empty vector called `l` to store the current combination being generated, and a vector of vectors called `result` to store all the valid combinations. It calls the `dfs` function with the `candidates` vector, the `target` sum, an initial `sum` of 0, a `start` index of 0, the empty combination `l`, and the `result` vector. After the function call, the `result` vector will contain all the unique combinations that sum up to the target value.
The time complexity of this solution depends on the number of valid combinations. In the worst case, where all possible combinations sum up to the target, the time complexity is exponential, O(2^n). The space complexity is also exponential as it depends on the number of valid combinations. However, it is important to note that the space used for the `result` vector is not counted in the space complexity analysis.

## 46. Permutations
This solution aims to find all possible permutations of a given set of numbers. The solution uses a depth-first search (DFS) approach to generate the permutations.
The solution defines a recursive helper function called `dfs`, which takes a vector of vectors `result` to store the permutations, the `start` index to keep track of the current position in the permutation, and the `nums` vector containing the numbers.
Within the `dfs` function, it first checks the base case: if the `start` index is equal to the size of the `nums` vector, it means that a complete permutation has been generated. In this case, the current permutation `nums` is added to the `result` vector.
Next, it starts a loop from the `start` index until the end of the `nums` vector. For each iteration, it swaps the element at index `i` with the element at the `start` index using the `std::swap` function. This step ensures that each element is placed at the current position in the permutation. Then, it recursively calls `dfs` with an updated `start` index to generate the next position in the permutation. After the recursive call, it swaps back the elements at indices `i` and `start` to backtrack and explore other possibilities in subsequent iterations.
The `permute` function serves as the entry point. It initializes an empty vector of vectors called `result` to store all the permutations. It calls the `dfs` function with the `result` vector, an initial `start` index of 0, and the `nums` vector. After the function call, the `result` vector will contain all the possible permutations of the numbers.
The time complexity of this solution is O(N!), where N is the number of elements in the `nums` vector. This is because there are N! possible permutations. The space complexity is also O(N!) as it grows linearly with the number of permutations.
Note: The solution assumes that the input vector `nums` does not contain any duplicate elements. If there are duplicate elements, the solution will generate duplicate permutations.

## 90. Subsets II
This solution aims to find all subsets of a given set of numbers, including duplicates. The solution uses a depth-first search (DFS) approach to generate the subsets.
The solution defines a recursive helper function called `dfs`, which takes a vector of vectors `result` to store the subsets, the `start` index to keep track of the current position in the subset, the `curr` vector to store the current subset being generated, and the `nums` vector containing the numbers.
Within the `dfs` function, it first adds the current subset `curr` to the `result` vector. This ensures that even an empty subset is included in the final result.
Next, it starts a loop from the `start` index until the end of the `nums` vector. For each iteration, it checks if the current index `i` is greater than the `start` index and if the element at index `i` is the same as the element at index `i - 1`. If these conditions are met, it skips to the next iteration to avoid generating duplicate subsets.
If the conditions are not met, it adds the element at index `i` to the `curr` vector, recursively calls `dfs` with an updated `start` index to generate the next position in the subset, and then removes the last element from `curr` to backtrack and explore other possibilities in subsequent iterations.
The `subsetsWithDup` function serves as the entry point. It first sorts the `nums` vector in ascending order. This step is necessary to ensure that duplicate elements are adjacent and can be easily skipped during subset generation.
It initializes an empty vector of vectors called `result` to store all the subsets. It also initializes an empty vector called `curr` to store the current subset being generated. It then calls the `dfs` function with the `result` vector, an initial `start` index of 0, the empty `curr` vector, and the sorted `nums` vector.
After the function call, the `result` vector will contain all the possible subsets of the numbers, including subsets with duplicates. The subsets are stored as individual vectors within the `result` vector.
The time complexity of this solution is O(2^N), where N is the number of elements in the `nums` vector. This is because there are 2^N possible subsets, and for each subset, the solution performs a constant amount of work. The space complexity is also O(2^N) as it grows linearly with the number of subsets.
Note: The solution assumes that the input vector `nums` may contain duplicate elements. If there are no duplicate elements, the solution will still work correctly.

## 40. Combination Sum II
This solution aims to find all unique combinations of numbers from a given set that sum up to a target value. The solution uses a depth-first search (DFS) approach to generate the combinations.
The solution defines a recursive helper function called `dfs`, which takes a vector of vectors `result` to store the combinations, the `start` index to keep track of the current position in the set, the `target` value to reach, the `curr` vector to store the current combination being generated, and the `candidates` vector containing the numbers.
Within the `dfs` function, it first checks if the `target` value is less than 0. If so, it means that the current combination has exceeded the target sum and is not valid. In such cases, it simply returns and proceeds to explore other possibilities.
Next, it checks if the `target` value is equal to 0. If so, it means that the current combination has reached the target sum and is a valid combination. In this case, it adds the `curr` vector to the `result` vector.
Then, it starts a loop from the `start` index until the end of the `candidates` vector. For each iteration, it checks if the current index `i` is greater than the `start` index and if the element at index `i` is the same as the element at index `i - 1`. If these conditions are met, it skips to the next iteration to avoid generating duplicate combinations.
If the conditions are not met, it adds the element at index `i` to the `curr` vector, recursively calls `dfs` with an updated `start` index and a reduced `target` value, and then removes the last element from `curr` to backtrack and explore other possibilities in subsequent iterations.
The `combinationSum2` function serves as the entry point. It first sorts the `candidates` vector in ascending order. This step is necessary to ensure that duplicate elements are adjacent and can be easily skipped during combination generation.
It initializes an empty vector of vectors called `result` to store all the combinations. It also initializes an empty vector called `curr` to store the current combination being generated. It then calls the `dfs` function with the `result` vector, an initial `start` index of 0, the `target` value, the empty `curr` vector, and the sorted `candidates` vector.
After the function call, the `result` vector will contain all the unique combinations of numbers from the `candidates` vector that sum up to the `target` value. The combinations are stored as individual vectors within the `result` vector.
The time complexity of this solution depends on the number of combinations generated. In the worst case, when there are no duplicate elements, the time complexity is O(2^N), where N is the number of elements in the `candidates` vector. This is because there can be up to 2^N possible combinations. However, if there are many duplicate elements, the time complexity can be improved as some combinations can be skipped. The space complexity is also O(2^N) as it grows linearly with the number of combinations.
Note: The solution assumes that the input vector `candidates` may contain duplicate elements. If there are no duplicate elements, the solution will still work correctly.

## 79. Word Search
This solution aims to determine if a given word can be formed by following adjacent letters in a 2D board. The solution uses a depth-first search (DFS) approach to explore all possible paths.
The first solution, named `exist2`, is considered better because it optimizes the backtracking process by marking visited tiles in-place on the board itself. This eliminates the need for a separate `markedTiles` vector to track visited tiles.
The `exist2` solution defines a recursive helper function called `dfs`, which takes the `board` vector, the `word` to search for, the current `index` of the word being matched, the `i` and `j` coordinates of the current tile, and the dimensions `m` and `n` of the board.
Within the `dfs` function, it first checks if the current position is out of bounds or if the current tile does not match the corresponding letter in the word. In such cases, it returns `false`, indicating that the current path is invalid and should be abandoned.
If the `index` is equal to the length of the word minus one, it means that the entire word has been matched, and thus, it returns `true`, indicating a successful match.
To mark the current tile as visited, it changes its value to a special character `'#'`.
Then, it recursively calls `dfs` on the neighboring tiles, incrementing the `index` by 1 and passing the updated coordinates and dimensions. If any of these recursive calls return `true`, it means that a valid path has been found, and it returns `true` from the current function call as well.
If none of the recursive calls lead to a valid path, it reverts the current tile back to its original value and returns `false` to backtrack and continue exploring other possibilities.
The `exist2` function serves as the entry point. It first initializes the dimensions `m` and `n` of the board by accessing the size of the vectors. Then, it iterates through all the tiles on the board, checking if the current tile matches the first letter of the word. If so, it calls the `dfs` function to explore the path starting from that tile. If a valid path is found, it returns `true`.
If no valid path is found after checking all the tiles, it returns `false`.
The second solution, named `exist`, follows a similar approach but uses a separate `markedTiles` vector to track visited tiles. It defines a helper function called `helper` that performs the depth-first search. It also keeps track of the current letter index and a boolean `result` to indicate if a valid path has been found.
The `exist` function iterates through all the tiles on the board, calling the `helper` function to explore paths starting from each tile. It passes the `result` variable by reference to update it if a valid path is found.
Both solutions have a time complexity of O(N * 3^L), where N is the number of cells in the board and L is the length of the word. This is because each cell can have at most 3 directions to explore (excluding the previous direction) during the depth-first search. The space complexity is O(L) as it depends on the recursive call stack to store the state of each call.
Note: The solutions assume that the input `board` and `word` are valid and within the specified constraints.

## 131. Palindrome Partitioning
This solution aims to find all possible palindrome partitions of a given string. It uses a depth-first search (DFS) approach to explore all possible combinations.
The solution consists of two main functions: `isPalindrome` and `dfs`, and an entry point function `partition`.
The `isPalindrome` function takes a string `s` and two indices `start` and `end`. It checks whether the substring from `start` to `end` (inclusive) is a palindrome. It does this by comparing characters at the corresponding indices from both ends of the substring. If any pair of characters is not equal, it returns `false`, indicating that the substring is not a palindrome. If all characters pairs are equal, it returns `true`, indicating that the substring is a palindrome.
The `dfs` function performs the depth-first search. It takes the input string `s`, a `start` index indicating the current position in the string, a `curr` vector to store the current palindrome partition, and a `result` vector to store all valid palindrome partitions.
The `dfs` function first checks if the `start` index has reached the end of the string. If so, it means that all characters have been processed, and the current partition in `curr` is a valid palindrome partition. It adds `curr` to `result` and returns.
Next, it starts a loop from the `start` index to the end of the string. For each index `i`, it checks if the substring from `start` to `i` is a palindrome using the `isPalindrome` function. If it is, it adds the substring to `curr`, then recursively calls `dfs` with the updated `start` index and `curr`. After the recursive call, it removes the last added substring from `curr` using `curr.pop_back()` to backtrack and try other combinations.
The `partition` function serves as the entry point. It takes the input string `s` and initializes the `result` and `curr` vectors. It then calls `dfs` with the initial `start` index as 0, `curr` as an empty vector, and `result` to store the final result.
The time complexity of this solution is O(N * 2^N), where N is the length of the input string `s`. This is because there can be 2^N possible partitions, and each partition requires O(N) time to check for palindromes. The space complexity is O(N) as it depends on the size of the call stack during the recursive DFS process.
Note: The solution assumes that the input `s` is valid and within the specified constraints.

## 17. Letter Combinations of a Phone Number
This solution aims to find all possible letter combinations of a given string of digits, where each digit corresponds to a set of letters on a phone keypad. It uses a depth-first search (DFS) approach to explore all possible combinations.
The solution consists of two main functions: `dfs` and an entry point function `letterCombinations`.
The `dfs` function takes the input string `digits`, a `str` string to store the current combination, a `start` index indicating the current position in the `digits` string, a `map` unordered map that maps each digit to its corresponding set of letters, and a `result` vector to store all valid combinations.
The `dfs` function first checks if the length of `str` is equal to the length of `digits`. If so, it means that a valid combination has been formed, and it adds `str` to `result` and returns.
Next, it retrieves the corresponding set of letters from the `map` using the current digit at `start`. It then iterates through each letter in the set and appends it to `str`. After that, it recursively calls `dfs` with the updated `start` index and the updated `str`. After the recursive call, it removes the last added letter from `str` using `str.pop_back()` to backtrack and try other combinations.
The `letterCombinations` function serves as the entry point. It takes the input string `digits` and initializes the `result` vector and an empty `str`. It also initializes the `map` unordered map with the corresponding digit-letter mappings.
The function first checks if the input `digits` is empty. If so, it returns an empty vector, as there are no letter combinations possible. If `digits` is not empty, it calls `dfs` with the initial `start` index as 0, the empty `str`, the `map`, and `result` to store the final result.
The time complexity of this solution is O(3^N * 4^M), where N is the number of digits that correspond to a set of 3 letters and M is the number of digits that correspond to a set of 4 letters. This is because each digit can have 3 or 4 possible letters, and there can be up to 3^N * 4^M possible combinations. The space complexity is O(N + M) as it depends on the size of the call stack during the recursive DFS process.
Note: The solution assumes that the input `digits` is valid and within the specified constraints.

## 51. N-Queens
This solution aims to find all possible solutions to the N-Queens problem, where N queens need to be placed on an N x N chessboard such that no two queens threaten each other. 
The solution uses a depth-first search (DFS) approach to explore all possible queen placements on the chessboard. It employs three unordered sets, `cols`, `negDiag`, and `posDiag`, to keep track of the occupied columns and diagonals. The `board` vector represents the current state of the chessboard.
The `dfs` function takes several parameters: `n` represents the size of the chessboard, `row` represents the current row being explored, `cols`, `negDiag`, and `posDiag` are unordered sets to keep track of the occupied columns and diagonals, `board` is a vector of strings representing the chessboard state, and `result` is a vector of vector of strings to store all valid solutions.
The `dfs` function first checks if `row` is equal to `n`, which indicates that all queens have been placed successfully. In this case, it adds the current `board` configuration to `result` and returns.
Next, it iterates through each column of the current `row`. For each column, it checks if the column, negative diagonal, or positive diagonal is already occupied. If any of them are occupied, it skips to the next column.
If the column is not occupied, it updates the sets `cols`, `negDiag`, and `posDiag` to mark the current queen's position. It also updates the corresponding cell on the `board` to represent the queen placement.
After updating the sets and `board`, it recursively calls `dfs` with the next row. Upon returning from the recursive call, it restores the previous state by removing the queen's position from the sets and resetting the corresponding cell on the `board`.
The `solveNQueens` function serves as the entry point. It takes the input `n` representing the size of the chessboard and initializes the `result` vector, `board` vector, and the sets `cols`, `negDiag`, and `posDiag`. It then calls `dfs` with the initial parameters to find all valid solutions.
The time complexity of this solution is O(N!), where N is the size of the chessboard. This is because the number of possible configurations grows factorially with the size of the chessboard. The space complexity is O(N) as it depends on the size of the call stack during the recursive DFS process.
