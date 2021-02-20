class MinStack
{
public:
    /** initialize your data structure here. */
    stack<long long int> s;
    long long int mn = INT_MAX;
    MinStack()
    {
    }

    void push(int x)
    {
        if (s.empty())
        {
            s.push(x);
            mn = x;
        }
        else if (x < mn)
        {
            s.push(2LL * x - mn);
            mn = x;
        }
        else
        {
            s.push(x);
        }
    }

    void pop()
    {
        if (s.top() < mn)
        {
            int temp = s.top();
            mn = 2 * mn - temp;
        }
        s.pop();
        if (s.empty())
        {
            mn = INT_MAX;
        }
    }

    int top()
    {
        if (s.top() < mn)
        {
            return mn;
        }
        return s.top();
    }

    int getMin()
    {
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */