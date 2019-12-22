/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (45.88%)
 * Likes:    1741
 * Dislikes: 116
 * Total Accepted:    352.6K
 * Total Submissions: 742.3K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string,vector<string>>m;
        for(auto i:strs)
            m[sorted(i)].push_back(i);
        for(auto i:m)
            res.push_back(i.second);
        return res;
        
    }
    string sorted(string a){
        sort(a.begin(),a.end());
        return a;
    }
};

