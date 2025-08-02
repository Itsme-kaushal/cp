#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        // 1. Count frequency of each fruit in both baskets
        for (int x : basket1) freq[x]++;
        for (int x : basket2) freq[x]++;

        // 2. If any fruit has odd count, impossible to balance
        for (auto& [_, count] : freq)
            if (count % 2) return -1;

        unordered_map<int, int> f1, f2;
        for (int x : basket1) f1[x]++;
        for (int x : basket2) f2[x]++;

        vector<int> swap1, swap2;
        // 3. Find excess fruits in each basket needing to be swapped
        for (auto& [fruit, total] : freq) {
            int ideal = total / 2;
            if (f1[fruit] > ideal)
                for (int i = 0; i < f1[fruit] - ideal; ++i)
                    swap1.push_back(fruit);
            if (f2[fruit] > ideal)
                for (int i = 0; i < f2[fruit] - ideal; ++i)
                    swap2.push_back(fruit);
        }
        // 4. Sort for greedy swapping: swap1 ascending, swap2 descending
        sort(swap1.begin(), swap1.end());
        sort(swap2.rbegin(), swap2.rend());

        // 5. Find the minimum fruit value across all baskets
        int minFruit = min(*min_element(basket1.begin(), basket1.end()), *min_element(basket2.begin(), basket2.end()));
        long long cost = 0, n = swap1.size();
        // 6. Compute minimum cost for each swap
        for (int i = 0; i < n; ++i)
            cost += min({swap1[i], swap2[i], 2 * minFruit});
        return cost;
    }
};

int main() {
    Solution sol;
    // Good test case (where swapping is beneficial)
    vector<int> basket1 = {8, 10, 12, 14, 2};
    vector<int> basket2 = {2, 8, 10, 14, 16};
    long long result = sol.minCost(basket1, basket2);
    cout << "Minimum cost to make both baskets equal: " << result << endl;
    // Expected output: 12 (explanation: swap 12 with 16 at cost min(12,16)=12)
    return 0;
}