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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* temp=head;
        while(temp != nullptr){
            count++;
            temp=temp->next;
        }
        count-=n;  //count=count-n=>starting se kitne chod kar delete karna hai
        if(count==0){    //if n=5 aa gya to count 0 ho jayega that's why startig wala delete krenge
            temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        ListNode*curr=head;
        ListNode*prev=nullptr;
        while(count--){     //jab tak count-- 0 na ho jaye tab tak curr aur prev ko aage badhao
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        delete curr; 
        return head;
    }
};