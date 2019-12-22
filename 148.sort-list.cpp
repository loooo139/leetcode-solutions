/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (34.68%)
 * Likes:    1549
 * Dislikes: 81
 * Total Accepted:    194K
 * Total Submissions: 535.9K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)return head;
        auto fast=head,slow=head,pre=head;
        while(fast&&fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre->next=nullptr;
        return megersort(sortList(head),sortList(slow));
    }
    ListNode *megersort(ListNode *l1,ListNode *l2){
        ListNode * dummy=new ListNode(-1);
        auto cur=dummy;
        while(l1&&l2){
            if(l1->val<l2->val){
                cur->next=l1;
                cur=cur->next;
                l1=l1->next;
            }
            else{
                cur->next=l2;
                cur=cur->next;
                l2=l2->next;
            }
        }
        if(l1)cur->next=l1;
        if(l2)cur->next=l2;
        return dummy->next;
    }
};

