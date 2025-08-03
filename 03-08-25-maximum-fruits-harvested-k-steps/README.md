Maximum Fruits Harvested After at Most K Steps
Problem Description
You are on an infinite x-axis and there are fruits available at some positions. You are given:

A 2D integer array fruits, where fruits[i] = [position_i, amount_i] indicates there are amount_i fruits at position position_i on the x-axis.

The array is sorted by position_i in ascending order, and each position is unique.

An integer startPos that is your starting position.

An integer k, the maximum number of steps you can take in total.

From the starting position, you can move left or right. Each movement by one unit costs one step. At each position you visit, you harvest all the fruits available there (which then disappear). Your objective is to maximize the total number of fruits harvested, but you cannot take more than k steps.

Return the maximum total number of fruits you can harvest.

Example 1
Input:

text
fruits = [[2,8],[6,3],[8,6]]
startPos = 5
k = 4
Output: 9

Explanation:

Move right to position 6, harvest 3 fruits.

Move right to position 8, harvest 6 fruits.

Total steps taken: 3. Total fruits: 3 + 6 = 9.

Example 2
Input:

text
fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]]
startPos = 5
k = 4
Output: 14

Explanation:

Harvest 7 fruits at position 5 (starting position).

Move left to 4: +1 fruit.

Move right to 6: +2 fruits.

Move right to 7: +4 fruits.

Steps used: 1 (to left) + 3 (to right) = 4. Total fruits: 7 + 1 + 2 + 4 = 14.

Example 3
Input:

text
fruits = [[0,3],[6,4],[8,5]]
startPos = 3
k = 2
Output: 0

Explanation:

Cannot reach any fruit position within 2 steps.

Constraints
1 <= fruits.length <= 1e5

fruits[i].length == 2

0 <= startPos, position_i <= 2e5

position_i-1 < position_i for all valid i > 0

1 <= amount_i <= 1e4

0 <= k <= 2e5