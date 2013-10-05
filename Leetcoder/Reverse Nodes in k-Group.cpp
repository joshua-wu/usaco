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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( NULL == head )
            return head;
        ListNode headhead(0);
        headhead.next = head; //add a head node
        head = &headhead;
        
        ListNode * rest;
        ListNode * pre = head;
        ListNode * deal;
        ListNode * p;

        while( 1 )
        {
           deal = pre;               
            //first to see if exist enough node left
            for( int i = 0; i < k && deal != NULL; i++ )
                 deal = deal->next;
            if( NULL == deal )
                break;
            
            rest = deal->next;
             
            //link the pre->next to rest 
            deal = pre->next;
            pre->next = rest;
             //now insert the k - 1 one
            for( int i = 0; i < k ; i++ )    
            {
                p = deal->next;
                deal->next = pre->next;
                pre->next = deal;
                deal = p;
             }     
             
             //now increase pre k step
             for( int i = 0; i < k; i++ )
                  pre = pre->next;          
        }
        
       return head->next;         
    }
};
