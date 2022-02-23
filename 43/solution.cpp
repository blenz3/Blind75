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

struct CmpListNodes
{
    bool operator()(const ListNode* lhs, const ListNode* rhs) const
    {
        return lhs->val > rhs->val;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) { 
            return nullptr;
        }
        
        std::priority_queue<ListNode*, vector<ListNode*>, CmpListNodes> pq;
        for (auto list : lists) {
            ListNode* runner = list;
            while (runner != nullptr) {
                ListNode* tmp = runner;
                pq.push(tmp);
                runner = runner->next;
                tmp->next = nullptr;
            }
        }
        
        ListNode* output = nullptr;
        ListNode* outRunner = nullptr;
        while (!pq.empty()) {
            auto tmp = pq.top();
            if (output == nullptr) {
                output = tmp;
                outRunner = tmp;
            } else {
                outRunner->next = tmp;
                outRunner = outRunner->next;
            }
            pq.pop();
        }
        
        return output;
        
        
    }
};
