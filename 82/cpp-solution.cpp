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
        ListNode* tailNode = nullptr;  
        ListNode* currentNode = head;  


        while (currentNode != nullptr){
            if (tailNode == nullptr || currentNode->val != tailNode->val){
                int counter = 0;
                ListNode* subNode = currentNode;
                while(subNode != nullptr && subNode->val == currentNode->val ){
                    counter++;
                    subNode = subNode->next;
                }
                if (counter > 1) {
                    currentNode = subNode;
                    continue;
                }
                
                if (tailNode == nullptr){
                    head = currentNode;
                }else {
                    tailNode->next = currentNode;
                }
                tailNode = currentNode;
            }
            currentNode = currentNode->next;
        }
        if (tailNode == nullptr) return tailNode;
        tailNode->next = nullptr;

        return head;
    }
};