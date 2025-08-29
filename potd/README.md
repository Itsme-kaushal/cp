# Alice and Bob Playing Flower Game

## Problem Statement (Easy Explanation)

Alice and Bob are playing a game with two rows (or lanes) of flowers.
- There are x flowers in the first lane and y flowers in the second lane.
- Alice always starts first.
- On each turn, a player picks one flower from any one of the lanes.
- The player who picks the last flower wins (because there will be no flower left for the next player!).

Given two numbers (n and m):
- x can be any number between 1 and n.
- y can be any number between 1 and m.
- We need to find out: For how many pairs (x, y) can Alice be guaranteed to win?

## Solution Approach

### Key Insight
If the sum (x + y) is odd, then Alice wins since she goes first and will also pick the last flower.
If it's even, then Bob wins, since he will be the one to pick the last flower.

### Why?
- Each player picks 1 flower per turn, reducing the total by 1.
- If the total is odd, Alice makes the last move.
- If even, Bob makes the last move.

### Efficient Calculation
Rather than checking every pair:
1. Count all pairs where x and y have different parity:
   - x is odd, y is even
   - x is even, y is odd
2. Let's compute:
   - Number of odd x: (n + 1) // 2
   - Number of even x: n // 2
   - Number of odd y: (m + 1) // 2
   - Number of even y: m // 2
3. Total pairs where Alice wins:
   - (n_odd * m_even) + (n_even * m_odd)

**Elegant Formula:**
Because exactly half the pairs have different parity:
Total pairs = (n * m) // 2

## Implementation

```cpp
class Solution {
public:
    long long flowerGame(int n, int m) {
        return 1LL * n * m / 2;
    }
};
```

## Example

Suppose n = 3, m = 2
Possible (x, y) pairs: (1,1), (1,2), (2,1), (2,2), (3,1), (3,2)

Those where (x + y) is odd:
- (1,2), (2,1), (3,2)
That's 3 pairs. Alice is guaranteed to win in these.

## Summary

- There are two rows with up to n and m flowers.
- Alice wins if the sum (x+y) is odd.
- The answer is always half of all possible (x, y) pairs.

**Final Answer Formula:**
Number of pairs Alice can win = (n × m) // 2