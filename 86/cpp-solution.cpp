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
    void printListNode(ListNode* head){
        while(head != nullptr){
            cout << head->val << ",";
            head = head->next;
        }
        cout << endl;
    }
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1;
        ListNode* leftNode = &dummy1;
        ListNode dummy2;
        ListNode* rightNode = &dummy2;

        while(head != nullptr){
            if (head->val < x){
                leftNode->next = head;
                leftNode = head;
            } else {
                rightNode->next = head;
                rightNode = head;
            }
            head = head->next;
        } 

        leftNode->next = dummy2.next;
        rightNode->next = nullptr;


        return dummy1.next;
    }
};