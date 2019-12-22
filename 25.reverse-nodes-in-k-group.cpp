/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (35.63%)
 * Total Accepted:    174.4K
 * Total Submissions: 487.7K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
 * 
 * Note:
 * 
 * 
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy;
        int num = 0;
        while (cur->next)
        {
            cur = cur->next;
            num++;
        }
        ListNode *pre = dummy;
        while (num >= k)
        {
            cur = pre->next;
            for (int i = 1; i < k; i++)
            {
                auto *tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
            }
            pre = cur;
            num -= k;
        }
        return dummy->next;
    }
};
