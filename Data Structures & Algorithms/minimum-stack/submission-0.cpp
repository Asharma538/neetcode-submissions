class MinStack {
    vector<int> s, m;
public:
    MinStack() {
        s.clear(), m.clear();
    }
    
    void push(int val) {
        if (s.size()){
            s.push_back(val);
            m.push_back(min(s[s.size()-1], m[m.size()-1]));
        } else {
            s.push_back(val);
            m.push_back(val);
        }
    }
    
    void pop() {
        m.pop_back();
        s.pop_back();
    }
    
    int top() {
        return s[s.size()-1];
    }
    
    int getMin() {
        return m[m.size()-1];
    }
};
