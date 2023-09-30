class Solution
{
    public:
        void merge(vector<int> &num1, int m, vector<int> &num2, int n)
        {
            vector<int> temp = num1;
            int i = 0, j = 0, k = 0;
            while (i < m && j < n)
            {
                if (temp[i] > num2[j])
                {
                    num1[k++] = num2[j++];
                }
                else
                {
                    num1[k++] = temp[i++];
                }
            }
            while (j < n)
            {
                num1[k++] = num2[j++];
            }
            while (i < m)
            {
                num1[k++] = temp[i++];
            }
            return;
        }
};