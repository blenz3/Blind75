/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Lazy solution
//  - Use a hashset to capture all of the pointers encountered and check to see if any node has been encountered before
//  - Space (linear)
//  - Time (linear)
class Solution {
public:
    
#if 0
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> encounteredNodes;
    
        ListNode* runner = head;
        while (runner !=  nullptr) {
            if (encounteredNodes.find(runner) !=  encounteredNodes.end()) 
                return true;
            
            encounteredNodes.insert(runner);
            
            runner = runner->next;
        }
        
        return false;
    }
#endif
    
    // Two runners which will meet eventually
    //  - one runner increments by 1 and the other by 2. Eventually they will meet if there is a cycle
    //    and if there is no cycle then we'll reach the end more quickly
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) 
            return false;
        
        ListNode* runner = head, *fastRunner = head->next;
        while (runner != nullptr && fastRunner != nullptr && fastRunner->next != nullptr) {
            if (runner == fastRunner) {
                return true;
            }
            
            runner = runner->next;
            fastRunner = fastRunner->next->next;
        }
        
        return false;
        
        
    }
};
