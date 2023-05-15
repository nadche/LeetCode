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
