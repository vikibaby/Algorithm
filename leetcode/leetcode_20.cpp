/**
 * use one stack
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ch : s){
            if(ch == '(' || ch == '{' || ch == '[')// 字符串用"，字符用'
                st.push(ch);
            else if(ch == ')' && !st.empty() && st.top() == '(')
                st.pop();
            else if(ch == '}' && !st.empty() && st.top() == '{')
                st.pop();
            else if(ch == ']' && !st.empty() && st.top() == '[')
                st.pop();
            else
                return false; // bool 函数 return false
        }
        return st.empty();
    }
};
