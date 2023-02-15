class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            int len = s.length(), mx = -1;
            bool visit[150] = {};
            int front = 0, end = 0;
            while (end != len)
            {
                if (visit[s[end]])
                {
                    if (mx < end - front)
                        mx = end - front;
                    while (s[front] != s[end])
                        visit[s[front++]] = false;
                    front++;
                }
                visit[s[end++]] = true;
            }
            if (mx < end - front)
                mx = end - front;
            return mx;
        }
};