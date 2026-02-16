// Last updated: 16/02/2026, 11:57:36
class Solution {
public:
    int calculate(string s) {
        int currentNumber = 0;
        if (!s.size()) return 0;
        char oper = '+';
        stack<int> stack;
        for (int i =0 ;i<s.size();i++){
            char current = s[i];
            if (isdigit(current)) currentNumber = (currentNumber*10) + (current-'0');
            if (!isdigit(current) && !iswspace(current) || i == s.size()-1){
                if (oper == '+') stack.push(currentNumber);
                else if (oper == '-') stack.push(-currentNumber);
                else if (oper == '*') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(currentNumber*stackTop);
                }
                else if (oper =='/'){
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop / currentNumber);
                }
                oper = current;
                currentNumber = 0;
            }
        }
        int result = 0;
        while (stack.size()){
            result += stack.top();
            stack.pop();
        }
        return result;
    }
};