/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (23.38%)
 * Likes:    558
 * Dislikes: 935
 * Total Accepted:    138.3K
 * Total Submissions: 580.6K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * Output: []
 * 
 * 
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>res;
        int m=s.size(),n=words.size();
        if(m==0||n==0)return res;
        map<string,int>dictP;
        for(auto i:words)dictP[i]++;
        int len=words[0].size();
        for(int i=0;i<len;i++){
            int left=i,cnt=0;
            map<string,int>dictS;
            for(int j=i;j<=m-len;j+=len){
                string tmp=s.substr(j,len);
                if(dictP.count(tmp)){
                    dictS[tmp]++;
                    if(dictS[tmp]<=dictP[tmp])cnt++;
                    else{
                        while(dictS[tmp]>dictP[tmp]){
                            auto str1=s.substr(left,len);
                            dictS[str1]--;
                            if(dictS[str1]<dictP[str1])cnt--;
                            left+=len;
                        }
                    }
                    if(cnt==n){
                        res.push_back(left);
                        dictS[s.substr(left,len)]--;
                        cnt--;
                        left+=len;
                    }
                }
                else{
                    dictS.clear();
                    cnt=0;
                    left=j+len;
                }
            }
        }
        return res;
    }
};

