/*
414. Third Maximum Number
Solved
Easy
Topics
premium lock icon
Companies
Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

 

Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.
Example 2:

Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.
Example 3:

Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Can you find an O(n) solution?
*/


// Have to find third largest number and each number should be distinct , and if there is no 3rd L no then return Largest no 
// it is a varition or advanced version of largest , 2nd largest , smallest , 2nd smallest numbers

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

        for (int num : nums) {
            if (num == first || num == second || num == third) continue;

            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }

        return (third == LONG_MIN) ? first : third;
    }
};

// OR 

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            long num = nums[i];

            // Skip duplicates
            if (num == first || num == second || num == third)
                continue;

            if (count == 0 || num > first) {
                third = second;
                second = first;
                first = num;
                count++;
            }
            else if (count == 1 || num > second) {
                third = second;
                second = num;
                count++;
            }
            else if (count == 2 || num > third) {
                third = num;
                count++;
            }
        }

        return (count >= 3) ? (int)third : (int)first;
    }
};
