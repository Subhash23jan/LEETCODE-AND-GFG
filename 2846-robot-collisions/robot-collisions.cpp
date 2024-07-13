class Solution
{
    public:
        vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
        {
            vector<pair<int, int>> vp;
            int n = positions.size();
            for (int i = 0; i < n; i++)
            {
                vp.push_back({ positions[i],
                    i });
            }
            sort(vp.begin(), vp.end());
            stack<int> st;
            int i = 0;
            while (i < n)
            {
                if (directions[vp[i].second] == 'R')
                {
                    st.push(vp[i].second);
                    i++;
                }
                else
                {

                    if (st.size() && directions[st.top()] == 'R')
                    {
                        if (healths[st.top()] > healths[vp[i].second])
                        {
                            i++;
                            healths[st.top()]--;
                        }
                        else if (healths[st.top()] < healths[vp[i].second])
                        {
                            healths[vp[i].second]--;
                            st.pop();
                        }
                        else
                        {
                            i++;
                            st.pop();
                        }
                    }
                    else
                    {
                        st.push(vp[i].second);
                        i++;
                    }
                }
            }
            vector<int> ans;
            vector<int> tmp;
            while (st.size())
            {
                tmp.push_back(st.top());
                st.pop();
            }
            sort(tmp.begin(), tmp.end());
            for (auto it: tmp)
            {
                ans.push_back(healths[it]);
            }
            return ans;
        }
};