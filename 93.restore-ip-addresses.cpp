/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (31.11%)
 * Likes:    704
 * Dislikes: 292
 * Total Accepted:    145.1K
 * Total Submissions: 454.9K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 * 
 * Example:
 * 
 * 
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 * 
 * 
 */
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>res;
        string path;
        dfs(res,path,s,0,0);
        return res;
    }
    void dfs(vector<string>&res,string path,string s,int index,int nums){
        if(index==s.size()&&nums==4){
            res.push_back(path.substr(1));
        }
        if(nums>=4)return ;
        if(s[index]=='0'){

            dfs(res,path+".0",s,index+1,nums+1);
        }else{
                    int val=0;
        while(index<s.size()&&val<=255){
            val=val*10+s[index++]-'0';

            if(val<256)dfs(res,path+"."+to_string(val),s,index,nums+1);

        }
        }
    }
};

