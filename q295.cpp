class MedianFinder
{
public:
    /** initialize your data structure here. */
    priority_queue<int> mxh;
    priority_queue<int, vector<int>, greater<int>> mnh;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        mxh.push(num);
        int temp = mxh.top();
        mxh.pop();
        mnh.push(temp);
        if (mxh.size() < mnh.size())
        {
            mxh.push(mnh.top());
            mnh.pop();
        }
    }

    double findMedian()
    {
        if (mxh.size() > mnh.size())
            return mxh.top();
        return ((double)mxh.top() + (double)mnh.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */