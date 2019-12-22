/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Friend Circles
 *
 * https://leetcode.com/problems/friend-circles/description/
 *
 * algorithms
 * Medium (54.23%)
 * Likes:    1098
 * Dislikes: 87
 * Total Accepted:    94.1K
 * Total Submissions: 173.3K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * 
 * There are N students in a class. Some of them are friends, while some are
 * not. Their friendship is transitive in nature. For example, if A is a direct
 * friend of B, and B is a direct friend of C, then A is an indirect friend of
 * C. And we defined a friend circle is a group of students who are direct or
 * indirect friends.
 * 
 * 
 * 
 * Given a N*N matrix M representing the friend relationship between students
 * in the class. If M[i][j] = 1, then the ith and jth students are direct
 * friends with each other, otherwise not. And you have to output the total
 * number of friend circles among all the students.
 * 
 * 
 * Example 1:
 * 
 * Input: 
 * [[1,1,0],
 * ⁠[1,1,0],
 * ⁠[0,0,1]]
 * Output: 2
 * Explanation:The 0th and 1st students are direct friends, so they are in a
 * friend circle. The 2nd student himself is in a friend circle. So return
 * 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * [[1,1,0],
 * ⁠[1,1,1],
 * ⁠[0,1,1]]
 * Output: 1
 * Explanation:The 0th and 1st students are direct friends, the 1st and 2nd
 * students are direct friends, so the 0th and 2nd students are indirect
 * friends. All of them are in the same friend circle, so return 1.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * N is in range [1,200].
 * M[i][i] = 1 for all students.
 * If M[i][j] = 1, then M[j][i] = 1.
 * 
 * 
 */
class Solution {
public:
    int find(vector<int>&nums,int i){
        if(nums[i]==-1)return i;
        else {
            int tmp=find(nums,nums[i]);
            nums[i]=tmp;
            return tmp;
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        vector<int>nums(n,-1);
        for(int i=0;i<n;i++)
            for(int j=0;j<i;j++){
                if(M[i][j]==1){
                    int a=find(nums,i);
                    int b=find(nums,j);
                    if(a!=b)nums[a]=b;
                }
            }
        int res=0;
        for(auto i:nums){
            if(i==-1)res++;
        }
        return res;
    }
};

