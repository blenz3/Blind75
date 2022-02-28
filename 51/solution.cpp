class Solution {
public:
    // Sliding window strategy - keep a running total of the most used characters starting 
    // both pointers from the same side. As long as the highest frequency character in the 
    // sliding window plus the replacements is good then we'll continue consuming. When we can no
    // longer consume then we pop off the left pointer and keep trying to the right
    int characterReplacement(string s, int k) {
        
        // If length is less than 2 than the value can only ever be 1 or 0 so just return
        // the length of the string immediately. If k == length then it'll just be k
        if (s.length() < 2 || k == s.length()) {
            return s.length();
        }
        
        int characterFrequencies[26];
        size_t frequencyLength = sizeof characterFrequencies / sizeof(int);
        ::memset(&characterFrequencies, 0, sizeof characterFrequencies);
        int left(0), right(0), maxLength(0);
        for (; right < s.length(); ++right) {
            // Increment the frequency map
            characterFrequencies[s[right] - 'A']++;
            if (right - left + 1 - maxFrequency(characterFrequencies, frequencyLength) > k) {
                characterFrequencies[s[left] - 'A']--;
                left++;
            }
            
            maxLength = std::max(maxLength, right - left + 1);
        }
            
        return maxLength;
    }


private:
    inline int maxFrequency(const int* frequencies, size_t length) {
        int max = 0;
        for (int i = 0 ; i < length; ++i) {
            max = std::max(frequencies[i], max);
        }
        
        return max;
    }
};
