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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) 
            return head;
        
        ListNode* newHead = nullptr;
        ListNode* runner = head;
        while (runner != nullptr) {
            // grab the latest node and prepend it to the new head
            ListNode* tmp = runner->next;
            runner->next = newHead;
            newHead = runner;
            runner = tmp;
        }
        
        return newHead;
    }
    
};
