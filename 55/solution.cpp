class Solution {
public:
    bool isValid(string s) {
        std::stack<char> parens;
        for (auto c : s) {
            if (isOpen(c)) {
                parens.push(c);
            } else if (parens.empty() ||  !matchingPair(parens.top(), c)) {
                return false;
            } else {
                parens.pop();
            }
        }
        
        // Mismatches also occur if there is anythiing left in the stack
        return parens.empty();
    }
private:
    bool isOpen(char c) {
        return (c == '(' || c == '{' || c == '[');
    }
    
    bool matchingPair(char c1, char c2) {
        return ((c1 == '(' && c2 == ')') ||
                (c1 == '{' && c2 == '}') ||
                (c1 == '[' && c2 == ']'));
    }
};
