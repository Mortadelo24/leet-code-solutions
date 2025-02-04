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
        ListNode* tailNode = head;  
        ListNode* currentNode = head->next;  

        while (currentNode != nullptr){
            if (currentNode->val != tailNode->val){
                cout << currentNode->val << endl;
                tailNode->next = currentNode;
                tailNode = currentNode;
            }
            currentNode = currentNode->next;
        }
        cout << tailNode->val << endl;

        return head;
    }
};