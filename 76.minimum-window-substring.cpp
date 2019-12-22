/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (30.36%)
 * Likes:    2340
 * Dislikes: 158
 * Total Accepted:    243.4K
 * Total Submissions: 784.5K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 * 
 */
class Solution {
public:
    string minWindow(string s, string t) {
        string res="";
        vector<int>letterCnt(128,0);
        int left=0,cnt=0,minLen=INT_MAX;
        for(char c:t) letterCnt[c]++;
        for(int i=0;i<s.size();i++){
            if(--letterCnt[s[i]]>=0)cnt++;
            while(cnt==t.size()){
                if(minLen>i-left+1){
                    minLen=i-left+1;
                    res=s.substr(left,minLen);
                }
                if(++letterCnt[s[left]]>0)--cnt;
                left++;
            }
        }
        return res;
    }
};

