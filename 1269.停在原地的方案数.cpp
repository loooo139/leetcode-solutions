/*
 * @lc app=leetcode.cn id=1269 lang=cpp
 *
 * [1269] 停在原地的方案数
 *
 * https://leetcode-cn.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description/
 *
 * algorithms
 * Hard (36.16%)
 * Likes:    14
 * Dislikes: 0
 * Total Accepted:    1.3K
 * Total Submissions: 3.6K
 * Testcase Example:  '3\n2'
 *
 * 有一个长度为 arrLen 的数组，开始有一个指针在索引 0 处。
 * 
 * 每一步操作中，你可以将指针向左或向右移动 1 步，或者停在原地（指针不能被移动到数组范围外）。
 * 
 * 给你两个整数 steps 和 arrLen ，请你计算并返回：在恰好执行 steps 次操作以后，指针仍然指向索引 0 处的方案数。
 * 
 * 由于答案可能会很大，请返回方案数 模 10^9 + 7 后的结果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：steps = 3, arrLen = 2
 * 输出：4
 * 解释：3 步后，总共有 4 种不同的方法可以停在索引 0 处。
 * 向右，向左，不动
 * 不动，向右，向左
 * 向右，不动，向左
 * 不动，不动，不动
 * 
 * 
 * 示例  2：
 * 
 * 输入：steps = 2, arrLen = 4
 * 输出：2
 * 解释：2 步后，总共有 2 种不同的方法可以停在索引 0 处。
 * 向右，向左
 * 不动，不动
 * 
 * 
 * 示例 3：
 * 
 * 输入：steps = 4, arrLen = 2
 * 输出：8
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= steps <= 500
 * 1 <= arrLen <= 10^6
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numWays(int steps, int arrLen) {
        if(arrLen==1)return 1;
        arrLen=min(arrLen,steps+1);
        const int k=1000000007;
        // vector<vector<long>>dp(steps+1,vector<long>(arrLen,0));
        vector<long>dp(arrLen,0);
        dp[0]=1;
        // for(int i=1;i<=steps;i++){
        //     dp[i][0]=(dp[i-1][1]+dp[i-1][0])%k;
        //     dp[i][arrLen-1]=(dp[i-1][arrLen-1]+dp[i-1][arrLen-2])%k;
        //     cout<<dp[i][0]<<endl;
        //     for(int j=1;j<arrLen-1;j++)
        //         dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]+dp[i-1][j+1])%k;
        // }
        // return dp[steps][0];
        for(int i=1;i<=steps;i++){
            vector<long>tmp(dp.size());
            tmp[0]=(dp[0]+dp[1])%k;
            tmp[arrLen-1]=(dp[arrLen-2]+dp[arrLen-1])%k;
            for(int j=1;j<=arrLen-2;j++)
                tmp[j]=((dp[j]+dp[j-1])%k+dp[j+1])%k;
            swap(tmp,dp);
        }
        return dp[0];

    }
};
// @lc code=end

