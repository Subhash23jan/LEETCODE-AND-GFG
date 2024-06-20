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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m=0,n=0;
        ListNode *temp=headA;
        while(temp)
        {
            m++;
            temp=temp->next;
        }
        temp=headB;
        while(temp){
            n++;
            temp=temp->next;
        }
        while(m>n && headA){
            cout<<headA->val<<" " << m<<endl;
            headA=headA->next;
            m--;
            
        }
        while(n>m && headB ){
            cout<<headB->val<<" " << n<<endl;
            n--;
            headB=headB->next;
           
        }
        while(headA && headB){
            if(headA==headB){
                return headA;
            }
             headA=headA->next;
             headB=headB->next;
        }
        return headA;

    }
};