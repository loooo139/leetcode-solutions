/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] < nums[right])
            {
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                {
                    right = mid - 1;
                }
            }
            else if (nums[mid] > nums[right])
            {
                if (target >= nums[left] && target < nums[mid])
                    right = mid - 1;
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                right--;
            }
        }
        return false;
    }
};
