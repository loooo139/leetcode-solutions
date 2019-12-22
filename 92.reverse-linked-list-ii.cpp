/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (34.54%)
 * Likes:    1296
 * Dislikes: 94
 * Total Accepted:    202.2K
 * Total Submissions: 571.7K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n)return head;
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *cur=dummy;
        for(int i=0;i<m-1;i++){
            cur=cur->next;
        }
        ListNode *a=cur,*r=cur->next,*end=cur->next;
        ListNode *temp=nullptr;
        for(int i=0;i<=n-m;i++){
            temp=r->next;
            r->next=cur->next;
            cur->next=r;
            r=temp;
        }
        end->next=temp;
        return dummy->next;

    }
};

