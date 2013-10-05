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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int min_idx;
        ListNode * l = NULL;
        ListNode * r = NULL;
        ListNode * p;
        while( 1 )
        {
               min_idx = -1;
               //to find the min
               for( int i = 0; i < lists.size(); i++ )
               {
                    if( lists[i] == NULL )
                        continue;
                    if( min_idx == -1 
                    || lists[min_idx]->val > lists[i]->val)
                        min_idx = i;
                }
                
                if( min_idx == -1 )
                    break;
                
                //now to insert
                p = lists[min_idx];
                lists[min_idx] = lists[min_idx]->next;
                if( r == NULL )
                {
                     l = p;
                     r = p;
                }
                else
                {
                    r->next = p;
                    r = r->next;
                }                                          
        }
        
        return l;
    }
};
