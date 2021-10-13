/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        long int l = 1, h = n;
        while (l <= h)
        {
            long int mid = l + (h - l) / 2;
            long int vr = guess(mid);
            if (vr == 0)
                return mid;
            if (vr == 1)
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return 0;
    }
};