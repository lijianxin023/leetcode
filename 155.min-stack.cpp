/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        size = 0;
    }
    
    void push(int x) {
        num.push_back(x);
        if(minNum.empty() || x<=minNum.back())
            minNum.push_back(x);
    }
    
    void pop() {
        if(num.back() == minNum.back())
            minNum.pop_back();
        num.pop_back(); 
    }
    
    int top() {
        return num.back();
    }
    
    int getMin() {
        return minNum.back();
    }
private:
    vector<int> num,minNum;
    int size;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

