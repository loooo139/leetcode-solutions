/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */
class Solution
{
public:
    int findDuplicate_(vector<int> &nums)
    {
        int slow = 0, fast = 0;
        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }
        fast = 0;
        while (true)
        {
            fast = nums[fast];
            slow = nums[slow];
            if (slow == fast)
                return slow;
        }
    }
    int findDuplicate(vector<int> &nums){
        int n=nums.size()-1;
        int left=1,right=n;
        while(left<right){
            int mid= left+right>>1;
            int cnt=0;
            for(auto i:nums){
                if(i>=left&&i<=mid)cnt++;
            }
            if(cnt>mid-left+1)right=mid;
            else left=mid+1;
        }
        return left;
    }
};
