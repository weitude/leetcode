class Solution
{
    public:
        int myAtoi(string s)
        {
            long long ans = 0;
            bool neg = false;
            int len = s.length(), idx = 0;
            while (idx < len)
            {
                if (s[idx] == ' ')
                    idx++;
                else
                    break;
            }
            if (idx == len)
                return 0;
            if (s[idx] == '-')
            {
                neg = true;
                idx++;
            }
            else if (s[idx] == '+')
                idx++;
            while (idx < len && '0' <= s[idx] && s[idx] <= '9' && ans <= 2147483648)
            {
                ans = ans * 10 + s[idx] - '0';
                idx++;
            }
            if (neg)
                ans *= -1;
            if (ans > INT_MAX)
                ans = INT_MAX;
            if (ans < INT_MIN)
                ans = INT_MIN;
            return ans;
        }
};

