/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.78%)
 * Likes:    1639
 * Dislikes: 0
 * Total Accepted:    134K
 * Total Submissions: 539.5K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * -4,-1,-1,0,1,2
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        if(nums.size()==0)return res;
        int i=0;
        while(i<nums.size()){
            if(i>0&&nums[i]==nums[i-1]&&i++)continue;
            int sums=-nums[i];
            int left=i+1,right=nums.size()-1;
            while(left<right){
                if(nums[left]+nums[right]==sums){
                    res.push_back({nums[i],nums[left],nums[right]});
                    while(left<right&&nums[left]==res.back()[1])left++;
                    while(left<right&&res.back()[2]==nums[right])right--;
                }
                else if(nums[left]+nums[right]>sums)right--;
                else left++;
            }
            i++;
        }
        return res;
    }
};
// @lc code=end

