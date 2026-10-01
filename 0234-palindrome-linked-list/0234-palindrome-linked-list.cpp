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
    bool isPalindrome(ListNode* head) {
        //find middle of linked list
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast != nullptr && fast->next != nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        //reverse the second half
        ListNode* prev=nullptr;
        ListNode* curr=slow;
        while(curr!= nullptr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        //compare first half and reversed second half
        ListNode* first=head;
        ListNode* second=prev;   // head pints to 1st list,prev points to 2nd list
        while(second!= nullptr){
            if(first->val != second->val){
                return false;
            }
            first=first->next;
            second=second->next;
        }
        return true;
    }
};