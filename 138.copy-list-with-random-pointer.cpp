/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution
{
public:
    map<Node *, Node *> mapper;
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        auto newHead = copyNew(head);
        auto cur = newHead;
        while (head)
        {

            cur->random = mapper[head->random];
            cur = cur->next;
            head = head->next;
        }
        return newHead;
    }
    Node *copyNew(Node *head)
    {
        Node *t = new Node(head->val, nullptr, nullptr);
        mapper[head] = t;
        if (head->next)
            t->next = copyNew(head->next);
        return t;
    }
};
