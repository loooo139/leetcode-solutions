/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (36.82%)
 * Likes:    715
 * Dislikes: 192
 * Total Accepted:    169.4K
 * Total Submissions: 449.2K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 * 
 * Example:
 * 
 * 
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* b=new ListNode(-1),*end=b;
        ListNode * a=new ListNode(-1),*pre=a;
        pre->next=head;
        while(pre->next!=nullptr){
            if(pre->next->val>=x){
                auto t=pre->next;
                pre->next=t->next;
                t->next=end->next;
                end->next=t;
                end=end->next;
            }
            else pre=pre->next;
        }
        pre->next=b->next;
        return a->next;
    }
};

