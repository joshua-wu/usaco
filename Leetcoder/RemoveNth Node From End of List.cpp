/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //with head
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * faster = head;
        ListNode * slower = head;
        //move the faster first
        for( int i = 0;  i < n + 1; i++ )
            faster = faster->next;
        
        while( faster != NULL )
        {
            faster = faster->next;
            slower = slower->next;
        }
        
        slower->next = slower->next->next;
        return head;
    } 
 
 
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * faster = head;
        ListNode * slower = NULL;
        //move the faster first
        for( int i = 0;  i < n ; i++ )
            faster = faster->next;
        
        while( faster != NULL )
        {
            faster = faster->next;
            if( NULL != slower )
                 slower = slower->next;
            else
                slower = head;
        }
        if( slower == NULL )
            head = head->next;
        else
            slower->next = slower->next->next;
        return head;
    }
};
