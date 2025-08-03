# Maximum Fruits Harvested After at Most K Steps

## Problem Description

You are on an infinite x-axis and there are fruits available at some positions. You are given:

- A 2D integer array **fruits**, where `fruits[i] = [position_i, amount_i]` indicates there are `amount_i` fruits at position `position_i` on the x-axis.  
  - The array is **sorted by** `position_i` in ascending order, and each position is **unique**.
- An integer **startPos** that is your starting position.
- An integer **k**, the maximum number of steps you can take in total.

From the starting position, you can move left or right. Each movement by one unit costs one step. At each position you visit, you harvest **all the fruits available there** (which then disappear). Your objective is to **maximize the total number of fruits harvested**, but you cannot take more than `k` steps.

Return the maximum total number of fruits you can harvest.

**Approach**:
- Use a sliding window over the sorted fruits array.
- For each interval, check if you can collect all fruits within `k` steps.
- Use prefix sums for fast calculation of total fruits in the interval.
- The process tries all possible valid intervals and returns the maximum total fruits collected.

---
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        // prefixSum[i] stores the total number of fruits from fruits[0] to fruits[i-1]
        vector<int> prefixSum(n+1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i+1] = prefixSum[i] + fruits[i][1];
        }

        // Function to get the sum of fruits between indices l and r (inclusive)
        auto getSum = [&](int l, int r) {
            return prefixSum[r+1] - prefixSum[l];
        };

        int maxFruits = 0;
        // Try all possible windows [left, right] such that positions are within k steps
        int left = 0;
        int right = 0;

        // Check all ranges where the left side is startPos-k to startPos and right side is to the right
        while (left < n && fruits[left][0] <= startPos + k) {
            // Move right as far as possible within k steps from startPos to fruits[right][0] and then to fruits[left][0]
            while (right < n && max( abs(startPos - fruits[left][0]) , abs(fruits[right][0] - startPos) ) + (fruits[right][0] - fruits[left][0]) <= k ) {
                right++;
            }
            // The window is [left, right-1]
            maxFruits = max(maxFruits, getSum(left, right-1));
            left++;
        }

        return maxFruits;
    }
};
```
---

## Example 1

**Input:**
### fruits = [[2,8],[6,3],[8,6]]
 ### startPos = 5
  ###k = 4
