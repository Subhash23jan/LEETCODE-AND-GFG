/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* modifiedList(vector<int> &nums, ListNode *head)
        {
            set<int> st(nums.begin(), nums.end());
            ListNode *ptr = head, *prev = nullptr;
            int cnt=0;
            while (ptr)
            {
                if (st.find(ptr->val) != st.end())
                {
                    cnt++;
                    if (prev == nullptr)
                    {
                        head = head->next;
                        delete ptr;
                        ptr = head;
                    }
                    else
                    {
                        prev->next = ptr->next;
                        delete ptr;
                        ptr = prev->next;
                    }
                }
                else
                {
                    prev = ptr;
                    ptr = ptr->next;
                }
            }
            return head;
        }
};