class Solution
{
    public:
        bool isValid(string s)
        {
            stack<char> stk;
            int len = s.length();
            for (int i = 0; i < len; i++)
            {
                char ch = s[i];
                if (stk.size() == 0)
                    stk.push(ch);
                else
                {
                    char top = stk.top();
                    if (ch == '(' || ch == '[' || ch == '{')
                        stk.push(ch);
                    else if (ch == ')' && top == '(')
                        stk.pop();
                    else if (ch == ']' && top == '[')
                        stk.pop();
                    else if (ch == '}' && top == '{')
                        stk.pop();
                    else
                        return false;
                }
            }
            if (stk.empty())
                return true;
            else
                return false;
        }
};

