/*
 * Author:             Brad Buckingham
 * Date Created:       10/1/2021
 * Date Last Modified: 10/1/2021
 *
 * Problem Source:
 * https://leetcode.com/problems/two-sum/
 *
 */
// ----------------------------------------------------------------------------
/*
 * Directions provided
 * https://leetcode.com/problems/two-sum/
 * Given an array of integers nums and an integer target, return indices of
 * the two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and you
 * may not use the same element twice.
 *
 * You can return the answer in any order.
 *
 * Example 1:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Output: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 * Example 2:
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 *
 * Example 3:
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 *
 * Constraints:
 * 2 <= nums.length <= 104
 * -109 <= nums[i] <= 109
 * -109 <= target <= 109
 * Only one valid answer exists.
 */
// ----------------------------------------------------------------------------
/*
 * Results
 * Runtime: 221 ms, faster than 30.86% of C++ online submissions for Two Sum.
 * Memory Usage: 10.2 MB, less than 80.23% of C++ online submissions for Two Sum.
 */
// ----------------------------------------------------------------------------

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        int size = nums.size();
        vector<int> ans;
        ans.resize(2);
        bool found = false;
        for(int i = 0; i < size-1 && !found; i++){
            int num1 = nums[i];
            for(int j = i+1; j < size && !found; j++){
                int num2 = + nums[j];
                if((num1 + num2) == target){
                    ans.at(0) = i;
                    ans.at(1) = j;
                    found = true;
                }
            }
        }
        return ans;
    }
};
