/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>map(256,0);
        int cnt=0;
        for(auto i:t){
            if(map[i]==0)cnt++;
            map[i]++;
        }
        string res="";
        for(int i=0,j=0,c=0;i<s.size();i++){
            if(map[s[i]]==1)c++;
            map[s[i]]--;
            while(c==cnt&&map[s[j]]<0)map[s[j++]]++;
            if(c==cnt){
                if(res.empty()||res.size()>i-j+1)
                    res = s.substr(j, i - j + 1);
            }
        }
        return res;
    }
};
// @lc code=end

