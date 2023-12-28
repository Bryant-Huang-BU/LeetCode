# Bryant’s Leetcode Notes

# ****Remove Duplicates from Sorted Array (Easy)****

## Problem:

Given an integer array `nums` sorted in **non-decreasing order**, remove the duplicates **[in-place](https://en.wikipedia.org/wiki/In-place_algorithm)** such that each unique element appears only **once**. The **relative order** of the elements should be kept the **same**. Then return *the number of unique elements in* `nums`.

Consider the number of unique elements of `nums` to be `k`, to get accepted, you need to do the following things:

- Change the array `nums` such that the first `k` elements of `nums` contain the unique elements in the order they were present in `nums` initially. The remaining elements of `nums` are not important as well as the size of `nums`.
- Return `k`.

## Found Solution:

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return 1;
        }
        vector<int> numsRep;
        //swap(nums, 0, 2); test statement for swap
        numsRep.push_back(nums[0]);
        int max = nums[0];
        for (int i = 1; i < nums.size(); i++) { //we're given the first num by default
            if (nums[i] > max) {
                max = nums[i];
                numsRep.push_back(nums[i]);
            }
        }
        nums = numsRep;
        return numsRep.size();
    }
    /*
    void swap (vector<int>& nums, int i, int j) {
        int swp;
        swp = nums[i];
        nums[i] = nums[j];
        nums[j] = swp;
    }*/
};
```

## Runtime and Memory Usage:

![Remove Duplicates from Sorted Array.png](images/Remove_Duplicates_from_Sorted_Array.png)

## Notes:

### Problem Assumptions:

As long as there is something in the vector, I will always be able to have an “anchor” of the highest value.

Because the problem array is sorted, I can get away with finding the max value and then skipping all duplicates in between 

### Solution Code:

Wanted to do a solution with swapping the actual vector elements itself, but the simulated vector came faster and easier to me, and given that I was timing myself, it seemed like the most optimal way to push an efficient solution out. O(N) time seemed good, I feel like I could’ve done with using a dynamic array for space efficiency but being able to simply set the parameter to my vector replica seemed very nice

### Runtime and Memory:

The Memory usage was around the same, but runtime would vary between apparently 0ms - 21 ms, with 3 runs at 4ms, 1 run at 0ms, 1 run at 21ms, 1 run at 18ms.


## Time spent to solve:
15 min

# Best Time to Buy and Sell Stock II

## Problem:

You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

On each day, you may decide to buy and/or sell the stock. You can only hold **at most one** share of the stock at any time. However, you can buy it then immediately sell it on the **same day**.

Find and return *the **maximum** profit you can achieve*.

## Found Solution:

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1) {
            return 0;
        }
        int high = prices[0], total = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > high) {
                total += (prices[i] - high);
                high = prices[i];
                //cout << "ADDED AT: " << i << " ";
                //cout << "total " << total << " high " << high << endl;
            }
            else if (prices[i] < high) {
                //cout << "CHANGED BUY SET FROM: " << high << " TO: " << prices[i] << endl;
                high = prices[i];
            }
        }
        return total;
    }
};
```

## Runtime and Memory Usage:

![Untitled](images/Best_Time_to_Buy_and_Sell_Stock_II.png)

## Notes:

### Problem Assumptions:

I have the knowledge of the future, not constrained to days

### Solution Code:

Felt like this was a decent solution, basically just iterated through the list looking for lows and highs, then replacing any lower prices with highs, selling whenever there was any profit to be had, using the greedy algorithm.

### Runtime and Memory:

Would’ve liked to known how I could’ve made memory usage more efficient, but I feel pretty satisfied with the runtime.

## Time Spent to Solve:

12 min
