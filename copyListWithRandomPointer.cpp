/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == 0) return 0;
        RandomListNode *p = head;
        while(p)
        {
            RandomListNode *new_node = new RandomListNode(p->label);
            RandomListNode *tmp = p->next;
            p->next = new_node;
            new_node->next = tmp;
            p = tmp;
        }
        p = head;
        while(p)
        {
            if(p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        RandomListNode *new_head = head->next;
        p = head;
        RandomListNode *p_new = new_head;
        while(p)
        {
            p->next = p->next->next;
            p = p->next;
            if(p_new->next)
            {
                p_new->next = p_new->next->next;
                p_new = p_new->next;
            }
        }
        return new_head;
    }
};
