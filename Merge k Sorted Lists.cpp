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
// struct compare {
//   bool operator()(const ListNode* l, const ListNode* r) {
//     return (l->val) > (r->val);
//    }
// };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return nullptr;
         auto comp =  [] (ListNode*l, ListNode *r) -> bool { return (l->val) > (r->val); };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq (comp);
        for(auto l : lists)
        {
            if(l)
                pq.push(l);
        }
        if(pq.empty())
            return nullptr;
        ListNode * result = pq.top();
        pq.pop();
        if(result->next)
        {
            pq.push(result->next);
        }
        ListNode *tail = result;
        while(!pq.empty())
        {
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
            if(tail->next)
            {
                pq.push(tail->next);
            }
        }
        return result;
    }
};