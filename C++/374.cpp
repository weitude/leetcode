/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
	public:
		int guessNumber(int n) {
			int l = 1, r = n;
			while(true) {
				int ans = l + (r - l) / 2;
				int result = guess(ans);
				if (result == 0)
					return ans;
				else if (result == 1)
					l = ans + 1;
				else
					r = ans;
			}
		}
};

