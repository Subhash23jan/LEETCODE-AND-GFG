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
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if (!head1)
            return head2;
        if (!head2)
            return head1;
        ListNode *dummy = new ListNode(0), *head;
        head = dummy;
        while (head1 && head2) {
            if (head1->val > head2->val) {
                head->next = head2;
                head = head->next;
                head2 = head2->next;
                head->next = NULL;
            } else {
                head->next = head1;
                head = head->next;
                head1 = head1->next;
                head->next = NULL;
            }
        }
        if (head1 != NULL)
            head->next = head1;
        if (head2 != NULL)
            head->next = head2;
        return dummy->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        for (auto it : lists) {
            head = merge(head, it);
        }
        return head;
    }
};