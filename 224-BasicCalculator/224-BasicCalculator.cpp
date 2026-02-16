// Last updated: 16/02/2026, 11:57:38
class Solution {
public:
    int calculate(string s) {
        long long num = 0 , sign = 1 , result = 0;
        stack<int> st;
        for (char c:s){
            if (isdigit(c)) num = num*10 + (c-'0');
            else if (c == '+'){
                result += sign*num;
                num = 0;
                sign = 1;
            }
            else if (c == '-'){
                result += sign*num;
                num = 0;
                sign = -1;
            }
            else if (c=='('){
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }
            else if (c == ')'){
                result += sign*num;
                num = 0;
                result *= st.top();st.pop();
                result +=st.top(); st.pop();
            }
        }
        result += num*sign;
        return result;
    }
};