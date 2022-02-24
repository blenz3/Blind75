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
    // Create two linked lists with the first half of the elements and then the second half. We then reverse the second half
    // and splice the two together
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return ;
        }
        
        int length = getLength(head);

        // Iterate  through  the first half of the nodes
        ListNode* firstHalf = head, *runner = head;
        for (int i = 0; i < (length / 2) - 1; ++i) {
            runner = runner->next;
        }
        
        // Disconnect and reverse  the second half
        ListNode* secondHalf = runner->next;
        runner->next = nullptr;
        secondHalf = reverseList(secondHalf);
        
        // Seed the output list with the first element of the 
        int counter(0);
        runner = nullptr;
        while (firstHalf != nullptr || secondHalf !=  nullptr) {
            ListNode*& nextNode = (getNextNode(firstHalf, secondHalf, counter++) == firstHalf) ? firstHalf : secondHalf;
            if (runner == nullptr) {
                runner = nextNode;
                nextNode = nextNode->next;
                runner->next = nullptr;
            } else {
                runner->next = nextNode;
                nextNode = nextNode->next;
                runner = runner->next;
                runner->next = nullptr;
            }
        }
        
    }
    
private:
    
    ListNode* getNextNode(ListNode* firstHalf, ListNode* secondHalf, int count) {
        if (count % 2 == 0) {
            return (firstHalf != nullptr)  ? firstHalf : secondHalf; 
        } else {
            return (secondHalf != nullptr) ? secondHalf : firstHalf;
        }
    }
    
    void printList(ListNode* head) {
        if (head == nullptr) 
            printf("Empty list");
        
        while (head != nullptr) {
            printf("%d ->", head->val);
            head = head->next;
        }
        
        printf("\n");
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* out = nullptr, *outRunner = nullptr;
        while (head != nullptr) {
            if (out == nullptr) {
                out = head;
                head = head->next;
                out->next = nullptr;
            } else {
                ListNode* tmp = head->next;
                head->next = out;
                out = head;
                head = tmp;
            }
        }
        
        return out;
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
