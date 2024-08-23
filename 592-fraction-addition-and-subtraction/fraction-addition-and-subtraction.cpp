class Solution
{
    public:
        string fractionAddition(string expression)
        {
            if (expression[0] != '-' && expression[0] != '+')
            {
                expression = '+' + expression;
            }
            long long num = 0, denom = 1;
            int i = 0, n = expression.size();

            while (i < n)
            {
                int sign = (expression[i++] == '-') ? -1 : 1;
                int currNum = 0;
                while (i < n && isdigit(expression[i]))
                {
                    currNum = currNum *10 + (expression[i++] - '0');
                }
                currNum *= sign;
                i++;	
                int currDenom = 0;
                while (i < n && isdigit(expression[i]))
                {
                    currDenom = currDenom *10 + (expression[i++] - '0');
                }

                num = num *currDenom + currNum * denom;
                denom *= currDenom;
                long long gcd = abs(std::gcd(num, denom));
                num /= gcd;
                denom /= gcd;
            }

            return to_string(num) + "/" + to_string(denom);
        }
};