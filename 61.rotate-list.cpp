/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (26.85%)
 * Likes:    640
 * Dislikes: 827
 * Total Accepted:    199.3K
 * Total Submissions: 726.6K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, rotate the list to the right by k places, where k is
 * non-negative.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, k = 2
 * Output: 4->5->1->2->3->NULL
 * Explanation:
 * rotate 1 steps to the right: 5->1->2->3->4->NULL
 * rotate 2 steps to the right: 4->5->1->2->3->NULL
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 0->1->2->NULL, k = 4
 * Output: 2->0->1->NULL
 * Explanation:
 * rotate 1 steps to the right: 2->0->1->NULL
 * rotate 2 steps to the right: 1->2->0->NULL
 * rotate 3 steps to the right: 0->1->2->NULL
 * rotate 4 steps to the right: 2->0->1->NULL
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
    ListNode* rotateRight(ListNode* head, int k) {
        int len=0;
        auto *tmp=head;
        while(tmp){
            len++;
            tmp=tmp->next;
        }
        if(len==0)return nullptr;
        if(k==0)return head;
        k%=len;
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *cur=dummy;
        while(k){
            cur=cur->next;
            k--;
        }
        tmp=dummy;
        while(cur->next){
            tmp=tmp->next;
            cur=cur->next;
        }
        cur->next=head;
        dummy->next=tmp->next;
        tmp->next=nullptr;
        return dummy->next;

    }
};

