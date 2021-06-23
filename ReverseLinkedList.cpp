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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)
            return head;
        
        
        ListNode* temp = head;
        ListNode dummy(0);
        
        ListNode* pre = &dummy;
        ListNode* cur;
        
        dummy.next =head;
        
        for(int i =0  ; i <left-1;i++)
        {
            pre = pre->next;
        }
        cur=pre->next;
        
        
        for(int i =0 ; i <right-left;i++)
        {
            ListNode * t = pre->next;
            pre->next= cur->next;
            cur->next = cur->next->next;
            pre->next->next = t;
        }
        return dummy.next;
        //find starting find
//         if(temp->val==left)
//             dummy.next = temp;
//         else{
//             while(temp->next->val != left)
//             {
//                 temp=temp->next;
//             }
//             dummy.next = temp->next;
//             temp->next = nullptr;
//         }
//         // ListNode tempHead(0);
//         // tempHead.next =  dummy.next ;
        
//         ListNode* result = nullptr;
//         ListNode* t = dummy.next;
//         for(ListNode* cur = dummy.next ; cur->val!=right;cur = cur->next)
//         {
//             cout<<t->val<<endl;
//             ListNode* current = new ListNode(t->val);
//             current->next = result;
//             result = current;
//             t = t->next;
//         }
        
        temp->next = dummy.next;
        return head;
    }
};