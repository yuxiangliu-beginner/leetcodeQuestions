/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return nullptr;
                
        ListNode new_head(-1);
        new_head.next = head;
        ListNode* first = &new_head ;
        ListNode* second = &new_head;
        
        for(int i = 0; i < n; i++)
            first = first->next;
        
        while(first ->next)
        {
            first = first->next;
            second = second->next;
        }
        
        // cout<<second->val<<endl;
        ListNode *to_de_deleted = second->next;
        second ->next = second->next->next;
        delete to_de_deleted;
        return new_head.next;
        
        
    }
};