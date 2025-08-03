# Maximum Fruits Harvested After at Most K Steps

## Problem Description

You are on an infinite x-axis and there are fruits available at some positions. You are given:

- A 2D integer array **fruits**, where `fruits[i] = [position_i, amount_i]` indicates there are `amount_i` fruits at position `position_i` on the x-axis.  
  - The array is **sorted by** `position_i` in ascending order, and each position is **unique**.
- An integer **startPos** that is your starting position.
- An integer **k**, the maximum number of steps you can take in total.

From the starting position, you can move left or right. Each movement by one unit costs one step. At each position you visit, you harvest **all the fruits available there** (which then disappear). Your objective is to **maximize the total number of fruits harvested**, but you cannot take more than `k` steps.

Return the maximum total number of fruits you can harvest.

---

## Example 1

**Input:**
### fruits = [[2,8],[6,3],[8,6]]
 ### startPos = 5
  ###k = 4
