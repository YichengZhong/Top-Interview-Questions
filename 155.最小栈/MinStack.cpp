class MinStack {
private:
    stack<int> dq_org, dq_min;  
    
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        dq_org.push(x);
        if (dq_min.empty() || x <= dq_min.top()) 
        {
            dq_min.push(x);
        }
    }
    
    void pop() {
        if (dq_min.top() == dq_org.top()) 
        {
            dq_min.pop();
        }
        dq_org.pop();
        
    }
    
    int top() {
        return dq_org.top();
    }
    
    int getMin() {
        return dq_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */