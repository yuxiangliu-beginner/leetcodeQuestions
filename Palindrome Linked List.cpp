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
    bool isPalindrome(ListNode* head) {
        ListNode * first = head;
        ListNode * slow = head;
        //find mid point
        while(first && first->next)
        {
            first = first->next->next;
            slow = slow->next;
        }
        if(first)
            slow = slow->next;
        
        
        //reverse 
        ListNode * dummy = slow;
        ListNode * last = nullptr;
        ListNode * next = nullptr;
        
        while(dummy)
        {
            next = dummy->next;
            dummy->next = last;
            last = dummy;
            dummy = next;
        }
        dummy = last;
        //comparing
        while(dummy)
        {
            if(dummy->val == head->val)
            {
                dummy = dummy->next;
                head = head->next;
            }
             else
                 return false;
        }
        return true;
        
    }
};