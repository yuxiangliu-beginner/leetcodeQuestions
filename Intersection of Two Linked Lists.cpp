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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/1092898/JS-Python-Java-C%2B%2B-or-Easy-O(1)-Extra-Space-Solution-w-Visual-Explanation
        
        //create two pointers point to a and b;
        ListNode * a= headA, *b = headB;
        
        
        //checking a != b
        while(a!=b)
        {
            //when one of pointer == nullptr, it will connect to another pointer.
            // Because the the intersection part is same.
            // combining two pointer will and loop every element will find the the same part.
            
            // a->same-> b ->same;
            // b -> same-> a-> same;
            // like we check each list twice.
            a = !a ? headB : a->next;
            b = !b ? headA : b->next;
        }
        return a;
    }
};