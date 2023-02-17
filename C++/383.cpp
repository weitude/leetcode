class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            int r[26] = {}, m[26] = {};
            int lenR = ransomNote.length();
            int lenM = magazine.length();
            for (int i = 0; i < lenR; i++)
                r[ransomNote[i] - 'a'] ++;
            for (int i = 0; i < lenM; i++)
                m[magazine[i] - 'a'] ++;
            for (int i = 0; i < 26; i++)
                if (r[i] > m[i])
                    return false;
            return true;
        }
};

