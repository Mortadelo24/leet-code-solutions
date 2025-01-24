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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k < 1) return head;
        int lastIndex = 0;
        ListNode* newEndNode = head;

        ListNode* currentNode = head;
        while (true){
            if (lastIndex > k){
                newEndNode = newEndNode->next;
            }

            if (!currentNode->next) break;
            lastIndex += 1;
            currentNode = currentNode->next;
        }

        int length = lastIndex + 1;
        if (k >= length ){
            int remainer = k % length;
            if (remainer > 0) return rotateRight(head, remainer);
            return head;
        }

        currentNode->next = head;
        head = newEndNode->next;
        newEndNode->next = nullptr;

        return head;
        
    }
};