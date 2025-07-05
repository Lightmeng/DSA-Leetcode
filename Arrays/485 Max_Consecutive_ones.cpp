/* Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2 */

// Basic logic 

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int high = 0; int count = 0;
        for(int i = 0 ; i< nums.size() ;i++)
        {
            if (nums[i]==1)
            {
                count = count +1;
                if (count > high)
                    high = count;
            }
            else if (nums[i]!=1)
            {
                if(count>=high)
                {
                    high = count;
                    count = 0;
                }
                else
                    count = 0;
                
            }
        }
        return high;
    }
};
