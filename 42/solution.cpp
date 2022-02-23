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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* outputList = nullptr;
        ListNode* outputRunner = nullptr;
        
        while (list1 != nullptr || list2 != nullptr) {
            int list1Value = (list1 == nullptr) ? INT_MAX : list1->val;
            int list2Value = (list2 == nullptr) ? INT_MAX : list2->val;
            
            ListNode* nextNode = nullptr;
            if (list1Value < list2Value) {
                nextNode = list1;
                list1 = list1->next;
            } else {
                nextNode = list2;
                list2 = list2->next;
            }
            
            if (outputList == nullptr) {
                outputList = nextNode;
                outputRunner = nextNode;
            } else {
                outputRunner->next = nextNode;
                outputRunner = outputRunner->next;
            }
        }
        
        return outputList;
    }
    
};
