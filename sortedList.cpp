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
    ListNode* sortList(ListNode* head) {
        if(!head||(!head->next))
            return head;
        
        ListNode * cur = head;
        int length = 0;
        //get length
        while(cur)
        {
            length++;
            cur = cur->next;
        }
        //point to head
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode * left, *right ,*tail;
        // int a = 8;
        // a <<= 1;
        // cout<<a<<"a=16"<<endl;
        for(int step = 1; step< length; step<<=1)
        {
            cur = dummy.next;
            tail = &dummy;
            while(cur)
            {
                //sort 
                left = cur;
                right = split(left,step);
                cur = split(right,step);
                tail = merge(left,right,tail);
            }
        }
        return dummy.next;
    }
private:
    ListNode* split(ListNode* head , int n)
    {
        for(int i = 1; head && i <n; i++)
            head =head->next;
        if(!head)
            return nullptr;
        ListNode* second = head->next;
        head->next = nullptr;
        return second;
    }
    ListNode* merge(ListNode* l1, ListNode* l2,ListNode* head)
    {
        ListNode* cur = head; 
        cout<<cur->val<<" ";
        while(l1 && l2)
        {
            if(l1->val > l2->val)
            {
                cur->next =l2;
                cur = l2;
                l2 = l2->next;
            }
            else
            {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
            // cout<<cur->val<<" ";
        }
     
        cur->next = (l1?l1:l2);
        // cout<<" after ";
        while(cur->next){
             // cout<<cur->val<<" ";
            cur = cur->next;
        }
             cout<<endl;  
        return cur;
    }
};