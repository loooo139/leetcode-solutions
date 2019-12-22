/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.43%)
 * Likes:    5996
 * Dislikes: 1568
 * Total Accepted:    1M
 * Total Submissions: 3.2M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy=new ListNode(-1);
        auto cur=dummy;
        int flag=0;
        while(l1||l2){
            int val=flag;
            if(l1)val+=l1->val;
            if(l2)val+=l2->val;
            auto tt=new ListNode(val%10);
            flag=val/10;
            cur->next=tt;
            cur=cur->next;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        if(flag)cur->next=new ListNode(1);
        return dummy->next;
        
    }
};

