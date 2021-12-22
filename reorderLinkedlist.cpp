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
    void reorderList(ListNode* head) {
        if(head==nullptr)
            return;
        //two pointer
        ListNode * fast = head;
        ListNode * slow = head;
        while(fast->next&& fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // cout<<slow->val<<endl;
        
        //reverse
        ListNode * prev =nullptr;
        ListNode *next = nullptr;
        while(slow!=nullptr)
        {
            next = slow->next;
            slow->next =prev;
            prev =slow;
            slow = next;
        }
        ListNode * revereHead=prev;
        // cout<<revereHead->val<<endl;
        //insert
        ListNode * headNext=nullptr;
        ListNode * revereHeadNext = nullptr;
        while(head!=nullptr && revereHead!=nullptr )
        {
            // cout<<head->val<<" "<<revereHead->val<<endl;
            headNext = head->next;
            revereHeadNext = revereHead->next;
            head->next = revereHead;
            revereHead->next = headNext;
            head = headNext;
            revereHead = revereHeadNext;
        }
         // if (head && head->next) head->next->next = NULL;
    }
};