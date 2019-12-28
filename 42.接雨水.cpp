/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (47.54%)
 * Likes:    753
 * Dislikes: 0
 * Total Accepted:    43.5K
 * Total Submissions: 91.3K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 * 
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>val(height.size());
        if(height.size()<3)return 0;
        int res=0;
        int maxHeight=0;
        for(int i=0;i<height.size();i++){
            maxHeight=max(maxHeight,height[i]);
            val[i]=maxHeight;
        }
        maxHeight=0;
        for(int i=height.size()-1;i>=0;i--){
            maxHeight=max(maxHeight,height[i]);
            int tmp=min(maxHeight,val[i]);
            if(tmp>height[i])res+=tmp-height[i];
        }
        return res;
    }
};
// @lc code=end

