// 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/
// In-place overwrite + fill zeroes

void moveZeroes(vector<int>& nums) {
    int count = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0) {
            nums[count++] = nums[i];
        }
    }
    for(int i = count; i < nums.size(); i++) {
        nums[i] = 0;
    }
}
