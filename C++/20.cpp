class Solution {
	public:
		bool isValid(string s) {
			stack<char> stk;
			int n = s.size();
			for (int i = 0; i < n; i++) {
				if (stk.size() == 0)
					stk.push(s[i]);
				else {
					if (s[i] == ')' && stk.top() == '(')
						stk.pop();
					else if (s[i] == '}' && stk.top() == '{')
						stk.pop();
					else if (s[i] == ']' && stk.top() == '[')
						stk.pop();
					else
						stk.push(s[i]);
				}
			}
			if (stk.size() == 0)
				return true;
			return false;
		}

};

