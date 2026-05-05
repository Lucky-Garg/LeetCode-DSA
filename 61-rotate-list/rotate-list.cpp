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
    ListNode* func(ListNode* head  , int diff){
        int cnt = 1;
        while(head != nullptr){
            if(cnt == diff)return head;
            cnt++;
            head = head -> next;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)return head;
        ListNode* tail = head;
        int cnt = 1;
        while( tail ->next != NULL){
            cnt ++;
            tail = tail -> next;
        }
        if(k % cnt == 0)return head;
        k = k % cnt;
        tail -> next = head;
        ListNode * newNode = func(head  , cnt - k);
        head = newNode -> next;
        newNode -> next = nullptr;
        return head;
    }
};