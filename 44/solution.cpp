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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = getLength(head);
        int removalIndex = length - n;
        if (removalIndex == 0) {
            return head->next;
        } else if (removalIndex == 1) {
            head->next = head->next->next;
            return head;
        }
        
        ListNode* previousRunner = head;
        ListNode* runner = head->next;
        for (int i = 0; i < removalIndex - 1; ++i) {
            previousRunner = previousRunner->next;
            runner = runner->next;
        }
        
        previousRunner->next = runner->next;
        return head;
    }
    
    int getLength(ListNode* head) {
        int count(0);
        while (head != nullptr) {
            count++;
            head = head->next;
        }
        
        return count;
    }
};
