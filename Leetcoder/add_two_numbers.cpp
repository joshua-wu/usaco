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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //guard
        ListNode * head = new ListNode( -1 );
        ListNode * cur = head;
        int carry = 0;
        int sum = 0;
        //now to loop
        while( l1 != NULL && l2 != NULL )
        {
            //add
            sum = l1->val + l2->val;
            sum += carry;
            
            cur->next = new ListNode( sum % 10 );
            carry = sum / 10;            


            //move forward
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        //if any list is not over
        ListNode *  p = l1==NULL?l2:l1;    
 
        while( NULL != p )
        {
            sum = p->val;
            sum += carry;            
            cur->next = new ListNode( sum % 10);
            carry = sum / 10;
            
            cur = cur->next;
            p = p->next;
        }
        
        
        
        if( carry != 0 )
            cur->next = new ListNode( carry );
        
        //drop the guard
        p = head;
        head = head->next;
        delete p;
        p = NULL;
        
        return head;
        
    }
};
