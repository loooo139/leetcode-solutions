/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (42.06%)
 * Total Accepted:    313.3K
 * Total Submissions: 742.7K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->1->2
 * Output: 1->2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->2->3->3
 * Output: 1->2->3
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(-1);
        if (head == nullptr)
            return nullptr;
        dummy->next = head;
        ListNode *cur = head;
        while (cur->next != NULL)
        {
            if (cur->next->val == cur->val)
            {
                cur->next = cur->next->next;
            }
            else
                cur = cur->next;
        }
        return dummy->next;
    }
};
