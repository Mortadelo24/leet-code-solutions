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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* tailNode = head;  
        ListNode* previousTailNode = head;
        ListNode* currentNode = head->next;  

        while (currentNode != nullptr){
            if (currentNode->val != tailNode->val){
                tailNode->next = currentNode;
                previousTailNode = tailNode;
                tailNode = currentNode;
            }else {
                tailNode = previousTailNode;
            }
            currentNode = currentNode->next;
        }
        tailNode->next = nullptr;

        return head;
    }
};