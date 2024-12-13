#include <bits/stdc++.h>
#define ll long long
class Solution
{
    public:
        long long findScore(vector<int> &nums)
        {
            int n = nums.size();
            vector<bool> marked(n, false);
            priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> minHeap;
           	//  the heap with all elements and their indices
            for (int i = 0; i < n; ++i)
            {
                minHeap.push({ nums[i],
                    i });
            }
            ll score = 0;
            while (!minHeap.empty())
            {
                int value = minHeap.top().first;
                int index = minHeap.top().second;
                minHeap.pop();
               	// Check if this element is already marked
                if (marked[index]) continue;
               	// Add the value to the score
                score += value;
               	// Mark this element and its adjacent elements
                for (int j = index - 1; j <= index + 1; j++)
                {
                    if (j >= 0 && j < n)
                    {
                        marked[j] = true;
                    }
                }
            }

            return score;
        }
};