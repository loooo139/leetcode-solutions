/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (32.37%)
 * Total Accepted:    174.2K
 * Total Submissions: 535.7K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->1->2->3
 * Output: 2->3
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
        if (head == nullptr)
            return nullptr;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy;
        while (head && head->next != nullptr)
        {
            if (head->val == head->next->val)
            {
                int val = head->val;
                head = head->next;
                while (head->next != nullptr && val == head->next->val)
                {
                    head = head->next;
                }
                cur->next = head->next;
                head = head->next;
            }
            else
            {
                head = head->next;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
