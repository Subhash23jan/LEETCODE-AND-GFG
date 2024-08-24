class Solution
{
    public:
        vector<int> nextGreaterElements(vector<int> &nums)
        {
            stack<int> st;
            for (int i = nums.size() - 1; i >= 0; i--)
                st.push(i);
            vector<int> ans(nums.size());
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                while (st.size() && nums[st.top()] <= nums[i])
                {
                    st.pop();
                }
                if (st.size())
                {
                    ans[i] = nums[st.top()];
                }
                else
                {
                    ans[i] = -1;
                }
                st.push(i);
            }
            return ans;
        }
};