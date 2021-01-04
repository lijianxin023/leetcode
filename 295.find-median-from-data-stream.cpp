/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> left_q;
    priority_queue<int,vector<int>,greater<int>> right_q; 

    MedianFinder(){
       
    }
    
    void addNum(int num) {
        left_q.push(num);
        right_q.push(left_q.top());
        left_q.pop();

        if(left_q.size()<right_q.size()){
            left_q.push(right_q.top());
            right_q.pop();
        }
    }

    double findMedian() {
        return left_q.size()>right_q.size()
                ? left_q.top()
                : (left_q.top() + right_q.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

