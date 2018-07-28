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
    struct s
    {
        bool operator() (const ListNode* a,const ListNode* b)
        {
            return a->val  > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode*, vector<ListNode*>, s>pq;
        for(auto i:lists)
        {
            if(i) 
            {
                pq.push(i);
            }
        }
        if(pq.empty())
        {
            return nullptr;
        }
        ListNode* ans = pq.top();
        pq.pop();
        ListNode* tail = ans;
        if(tail->next)
        {
            pq.push(tail->next);
        }
        while(!pq.empty())
        {
            tail->next = pq.top();
            tail = tail->next;
            pq.pop();
            if(tail->next)
            {
                pq.push(tail->next);
            }
        }
        return ans;
    }
};