// Last updated: 27/03/2026, 01:37:59
class MinStack {
public:
    vector<int> st;
    vector<int> min_st = {INT_MAX};
    MinStack() {
    
    }
    
    void push(int val) {
        st.push_back(val);
        if (min_st[min_st.size()-1]>=val) min_st.push_back(val);
    }
    
    void pop() {
        if (st.size()) {
            if (st[st.size()-1] == min_st[min_st.size()-1]) min_st.pop_back();
            st.pop_back();
        }
    }
    
    int top() {
        return st.size() ? st[st.size()-1] : 0;
    }
    
    int getMin() {
        return min_st.size() ? min_st[min_st.size()-1] : 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */