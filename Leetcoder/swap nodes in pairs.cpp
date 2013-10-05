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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( NULL == head || head->next == NULL )
            return head;
        
        ListNode * fast = head->next;
        ListNode * slow = head;
        
        while( 1 )
        {
               swap( fast->val, slow->val );
               if( (fast= fast->next) == NULL ||
                   (fast = fast->next) == NULL )
                   break;
               slow=slow->next->next;
        }
        
        return head;
    }
}; 


class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( NULL == head || head->next == NULL )
            return head;
        
        ListNode * pre = NULL;
        ListNode * fast = head->next;
        ListNode * slow = head;
        ListNode * rest;
        
        while( 1 )
        {
               rest = fast->next;
               if( pre == NULL )
                   head = fast;
               else
                   pre->next = fast;
                           
               fast->next = slow;
               slow->next = rest;
               pre = slow;
               
               slow = fast;
               fast = pre;
               
               if( (fast= fast->next) == NULL ||
                   (fast = fast->next) == NULL )
                   break;
               slow=slow->next->next;
        }
        
        return head;
    }
}; 
