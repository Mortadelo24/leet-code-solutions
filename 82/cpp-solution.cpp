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
            if (currentNode->val != tailNode->val){
                int counter = 0;
                ListNode* subNode = currentNode;
                while(subNode != nullptr && subNode->val == currentNode->val ){
                    counter++;
                    subNode = subNode->next;
                }
                cout << currentNode->val << " : " <<  counter << endl;

                tailNode->next = currentNode;
                tailNode = currentNode;
            }
            currentNode = currentNode->next;
        }
        tailNode->next = nullptr;

        return head;
    }
};