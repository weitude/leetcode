class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        string ans = "";
        int len = s.length(), lgap = (numRows - 1) * 2, rgap = 0;
        for (int i  =0;i  < numRows; i++)
        {
            int pos = i;
            while (pos < len)
            {
                if (lgap != 0)
                {
                    ans += s[pos];
                    pos += lgap;
                }
                if (pos >= len)
                    break;
                if (rgap != 0)
                {
                    ans += s[pos];
                    pos += rgap;
                }
            }
            lgap-= 2;
            rgap+= 2;
        }
        return ans;
    }
};