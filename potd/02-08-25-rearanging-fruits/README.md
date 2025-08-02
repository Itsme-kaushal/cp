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


**Constraints:**
- basket1.length == basket2.length
- 1 <= basket1.length <= 1e5
- 1 <= basket1[i], basket2[i] <= 1e9

---

## Thought Process & Optimal Solution

1. **Count frequency of each fruit (number) in both baskets.**
2. **If any fruit appears an odd number of times in total, return -1** (it's impossible to split them equally).
3. **Find extra fruits in each basket**:
    - For every fruit, calculate the difference between count in basket1 and half of the total count.
    - If basket1 has too many, put those fruits in `swap1`; if basket2 has too many, put them in `swap2`.
4. **Sort swap1 in ascending order and swap2 in descending order**. This ensures the cheapest possible swaps.
5. **Calculate the minimum cost for each pair of items to swap**:
    - For each i, the swap cost is `min(swap1[i], swap2[i], 2 * minFruit)`.
    - Sometimes swapping via the globally minimum fruit (`minFruit`) in two steps is cheaper than direct swapping.
6. **Sum all chosen swap costs for the solution**.

---

## Pseudocode

C++
```cpp
#include <vector>
#include <unordered_map>
#include <algorithm>    
using namespace std;
int minCostToRearrangeFruits(vector<int>& basket1, vector<int>& basket2) {
    unordered_map<int, int> count1, count2;
    for (int fruit : basket1) count1[fruit]++;
    for (int fruit : basket2) count2[fruit]++;
    
    int totalCost = 0;
    vector<int> swap1, swap2;
    
    // Find the minimum fruit value
    int minFruit = min(*min_element(basket1.begin(), basket1.end()), *min_element(basket2.begin(), basket2.end()));
    
    // Check counts and prepare swap lists
    for (const auto& [fruit, count] : count1) {
        int totalCount = count + count2[fruit];
        if (totalCount % 2 != 0) return -1; // Impossible to balance
        
        int halfCount = totalCount / 2;
        if (count > halfCount) {
            swap1.insert(swap1.end(), count - halfCount, fruit);
        } else if (count < halfCount) {
            swap2.insert(swap2.end(), halfCount - count, fruit);
        }
    }
    
    // Sort swap lists
    sort(swap1.begin(), swap1.end());
    sort(swap2.rbegin(), swap2.rend());
    
    // Calculate total cost
    for (size_t i = 0; i < swap1.size(); ++i) {
        totalCost += min({swap1[i], swap2[i], 2 * minFruit});
    }
    
    return totalCost;
}
```