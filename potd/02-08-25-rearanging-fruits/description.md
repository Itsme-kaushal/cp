# LeetCode 2561: Rearranging Fruits

**Description:**
Given two baskets containing `n` fruits each, represented by two integer arrays `basket1` and `basket2` (costs of fruits), your goal is to make both baskets *identical* (when sorted) by swapping fruits between them any number of times. The cost of each swap is the minimum of the two swapped fruit values.

**Task:**  
Return the minimum total swap cost to make both baskets equal. If it's impossible, return -1.

**Examples:**
- **Input:**  
  basket1 = [4,2,2,2], basket2 = [1,4,1,2]  
  **Output:** 1

- **Input:**  
  basket1 = [2,3,4,1], basket2 = [3,2,5,1]  
  **Output:** -1

**Constraints:**
- basket1.length == basket2.length
- 1 <= basket1.length <= 1e5
- 1 <= basket1[i], basket2[i] <= 1e9
