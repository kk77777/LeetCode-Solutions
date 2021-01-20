class Solution
{
public:
    int findGap(int cg)
    {
        if (cg <= 1)
            return 0;
        int gap = cg / 2 + (cg % 2);
        return gap;
    }

    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int gap = findGap(m + n);
        int i = 0, j = 0;
        while (gap)
        {
            for (i = 0; i + gap < m; i++)
            {
                if (nums1[i] > nums1[i + gap])
                {
                    swap(nums1[i], nums1[i + gap]);
                }
            }
            for (int j = gap > m ? gap - m : 0; i < m && j < n; i++, j++)
            {
                if (nums1[i] > nums2[j])
                {
                    swap(nums1[i], nums2[j]);
                }
            }
            if (j < n)
            {
                for (j = 0; j + gap < n; j++)
                {
                    if (nums2[j] > nums2[j + gap])
                        swap(nums2[j], nums2[j + gap]);
                }
            }
            gap = findGap(gap);
        }
        for (int i = 0; i < n; i++)
        {
            nums1[i + m] = nums2[i];
        }
    }
};