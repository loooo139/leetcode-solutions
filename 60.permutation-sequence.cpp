/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (32.74%)
 * Likes:    880
 * Dislikes: 230
 * Total Accepted:    142K
 * Total Submissions: 424.6K
 * Testcase Example:  '3\n3'
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * Given n and k, return the k^th permutation sequence.
 * 
 * Note:
 * 
 * 
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, k = 3
 * Output: "213"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4, k = 9
 * Output: "2314"
 * 
 * 
 */
class Solution {
public:
    string getPermutation(int n, int k) {
       string nums="123456789";
       vector<int>f(n+1,1);
       string res;
       for(int i=1;i<=n;i++)
            f[i]=f[i-1]*i;
        k--;
        for(int i=n;i>0;i--){
            int j=k/f[i-1];
            //cout<<"k:"<<k<<endl;
            k%=f[i-1];
            res.push_back(nums[j]);
            nums.erase(j,1);
            //cout<<nums<<endl;
        } 
        return res;
    }
};

