class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        long long int rev = 0, temp = x;
        while (x != 0)
        {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        if (temp == rev)
            return true;
        return false;
    }
};