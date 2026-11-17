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
    ListNode* swapPairs(ListNode* head) {
        //base case:0 or 1 node
        if(head==NULL || head->next==NULL){
            return head;
        }
        //store the second node
        ListNode *second=head->next;
        //recursively swap the remainingnodes
        head->next=swapPairs(second->next);
        //swap the 1st nodes
        second->next=head;
        //second node becomes the new node
        return second;
    }
};