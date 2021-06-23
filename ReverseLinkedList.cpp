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
//     ListNode* ans;
//     ListNode* reverse(ListNode* head,ListNode* res)
//     {
// //         if(head->next==nullptr)
// //         {
// //             res= head;
// //             ans= head;
// //             return head;
// //         }
            
// //         ListNode* re = reverse(head->next,res);
// //         res->next =  new ListNode(head->val);
// //         res = res->next;
// //         return head;
//     }
    ListNode* reverseList(ListNode* head) {
        // ListNode* res = nullptr;
        // return reverse(head,res);
        
//         if(!head || !(head->next))
//             return head;
//         ListNode * root = reverseList(head->next);
//         head ->next->next = head;
//         head->next = nullptr;
//         return root;
        
        
        
//         if (!head || !(head -> next)) {
//             return head;
//         }
//         // ListNode* node = reverseList(head -> next);
//         // cout<<node->val<<" "<<head->val<<endl;
//         // head -> next -> next = head;
//         // head -> next = NULL;
//         // return node;
        
//         ListNode* node = reverseList(head -> next);
//         head->next->next =head;
//         head ->next = nullptr;
//         return node;
        
    // }
        // ListNode* result = nullptr;
        // ListNode* t = head;
        // while (t != nullptr)
        // {
        //     ListNode* current = new ListNode(t->val);
        //     current->next = result;
        //     result = current;
        //     t = t->next;
        // }
        // return result;
        
        
        // //recursion
        // if (!head || !(head -> next)) {
        //     return head;
        // }
        // ListNode* node = reverseList(head -> next);
        // head -> next -> next = head;
        // head -> next = NULL;
        // return node;
        
        //iterative
        ListNode *pre = new ListNode(0), *cur = head;
        pre -> next = head;
        while (cur && cur -> next) {
            ListNode* temp = pre -> next;
            pre -> next = cur -> next;
            cur -> next = cur -> next -> next;
            pre -> next -> next = temp;
        }
        return pre -> next;
        
        
        
	}
};