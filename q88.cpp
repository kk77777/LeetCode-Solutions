class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        bool flag = 1;
        int k = 0;
        if (nums2.size() == 0)
            return;
        for (int i = 0; i < m; i++)
        {
            k = 0;
            flag = 1;
            if (nums1[i] > nums2[0])
            {
                swap(nums1[i], nums2[0]);
                for (int j = 1; j < n && flag != 0; j++)
                {
                    if (nums2[k] > nums2[j])
                    {
                        swap(nums2[k], nums2[j]);
                        k = j;
                    }
                    else
                    {
                        flag = 0;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            nums1[i + m] = nums2[i];
        }
    }
};