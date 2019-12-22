/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (47.70%)
 * Likes:    2103
 * Dislikes: 65
 * Total Accepted:    356K
 * Total Submissions: 724.7K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>tmp;
        sort(candidates.begin(),candidates.end());
        if(target<candidates[0])return res;
        DFS(res,tmp,candidates,target,0);
        return res;
    }
    void DFS(vector<vector<int>>&res,vector<int>&tmp,vector<int>candi,int target,int index){
        if(target==0){
            res.push_back(tmp);
            return ;
        }
        if(target<0) return ;
        for(int i=index;i<candi.size();i++){
            if(candi[i]<=target){
                tmp.push_back(candi[i]);
                DFS(res,tmp,candi,target-candi[i],i);
                tmp.pop_back();
            }
        }
        
    }
};

