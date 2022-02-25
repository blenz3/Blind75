class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() < 2) {
            return true;
        }
        
        int begin = 0, end = s.size() - 1;
        while (begin < end) {
            // move begin pointer to the next valid character
            while (begin < s.size() && !isValidCharacter(s[begin]))
                begin++;
            
            //move end pointer to the next valid character
            while (end > 0 && !isValidCharacter(s[end])) 
                end--;
            
            if (begin > end) {
                break;
            }
            
            if (::tolower(s[begin]) != ::tolower(s[end])) 
                return false;
            
            begin++;
            end--;
        }
        
        return true;
    }

private:
    bool isValidCharacter(char c) {
      return (::isalpha(c) || ::isdigit(c));
    }
};
