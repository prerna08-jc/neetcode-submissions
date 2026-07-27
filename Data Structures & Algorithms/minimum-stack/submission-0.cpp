class MinStack {
    stack <pair<int,int>> st;
    int mini;
public:
    MinStack() {
    }
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }
        else{
            mini=min(st.top().second,val);
            st.push({val,mini});
        }
    }
    
    void pop() {
        if(st.empty())
            return;
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
