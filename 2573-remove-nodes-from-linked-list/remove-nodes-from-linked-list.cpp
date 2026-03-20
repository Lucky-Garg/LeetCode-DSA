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
    ListNode* rev(ListNode*head){
        ListNode*prev = NULL;
        ListNode*temp = head;
        ListNode*forw;
        while(temp!=NULL){
            forw = temp->next;
            temp->next = prev;
            prev = temp;
            temp = forw;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode*temp = rev(head);
        ListNode*dummy = new ListNode(temp->val);
        ListNode*curr = dummy;
        int maximum = temp->val;
        temp = temp->next;
        while(temp!=NULL){
            if(temp->val >= maximum){
                curr->next = temp;
                curr = curr->next;
                maximum = temp->val;
            }
            temp = temp->next;
        }
        curr->next = NULL;
        return rev(dummy);
    }
};