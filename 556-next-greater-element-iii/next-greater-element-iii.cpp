class Solution
{
    public:
        int nextGreaterElement(int n)
        {
            string str = "";
            while (n)
            {
                str = (char)(n % 10 + '0') + str;
                n /= 10;
            }

            int i = str.size() - 2;

           	// Find the rightmost digit which is smaller than its next digit
            while (i >= 0 && str[i] >= str[i + 1])
            {
                i--;
            }

            if (i < 0)	// No such digit found, meaning the digits are in descending order
            {
                return -1;
            }

           	// Find the smallest digit on the right side of (i) which is larger than str[i]
            int j = str.size() - 1;
            while (str[j] <= str[i])
            {
                j--;
            }

           	// Swap the digits
            swap(str[i], str[j]);

           	// Sort the digits after position i in ascending order
            sort(str.begin() + i + 1, str.end());

           	// Convert back to integer and check for overflow
            long long ans = stoll(str);
            return (ans > INT_MAX) ? -1 : static_cast<int> (ans);
        }
};