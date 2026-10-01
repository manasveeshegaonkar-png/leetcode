/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        //step1: check if a cycle exists
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if( slow==fast){
                //step2: find the starting node of the cycle
                ListNode* start=head;
                while(start!=slow){
                    start=start->next;
                    slow=slow->next;
                }
                return start;
            }
        }
        //no cycle
        return nullptr;

    }
};