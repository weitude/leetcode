class Solution {
	public:
		int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
			unordered_set<string> visited, exist(wordList.begin(), wordList.end());
			queue<string> q;
			q.push(beginWord);

			int cnt = 1, len = beginWord.length();
			while(!q.empty())
			{
				int size = q.size();
				for (int i = 0; i < size; i++)
				{
					string curr = q.front();
					if (curr == endWord)
						return cnt;
					q.pop();
					for (int j = 0; j < len; j++)
					{
						string temp = curr;
						for (char ch = 'a'; ch <= 'z'; ch++)
						{
							temp[j] = ch;
							if (exist.count(temp) && !visited.count(temp))
							{
								q.push(temp);
								visited.insert(temp);
							}
						}
					}
				}
				cnt++;
			}
			return 0;
		}
};

