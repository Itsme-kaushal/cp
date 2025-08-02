# Pascal's Triangle – LeetCode Solution

This repository contains a C++ solution for the [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/) problem from LeetCode.

## Problem Description

Given an integer `numRows`, generate the first `numRows` of Pascal's Triangle.

**In Pascal's Triangle:**
- Each number is the sum of the two numbers directly above it.
- The first and last numbers in each row are always `1`.

**Example:**


## Solution Approach

- Initialize a 2D vector to store rows.
- For each row, fill the edges with `1`.
- For other positions, set value as the sum of the two above it.
- Push each row into the main vector.

### C++ Code

```
class Solution {
public:
vector<vector<int>> generate(int numRows) {
vector<vector<int>> pascal;
for (int i = 0; i < numRows; i++) {
vector<int> row(i + 1, 1);
for (int j = 1; j < i; j++) {
row[j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
}
pascal.push_back(row);
}
return pascal;
}
};
```