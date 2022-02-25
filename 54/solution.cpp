class Solution {
public:
#if 0
    //  sorting nlgn solution
    //      - For each string insert into a hashmap the sorted equivalent of the string
    //      - pull them all out and dump them in a coalesced vector
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram_groups;
        for (int i = 0; i < strs.size(); ++i) { 
            string s_copy(strs[i]);
            std::sort(s_copy.begin(), s_copy.end());
            anagram_groups[s_copy].push_back(strs[i]);
        }
        
        vector<vector<string>> out;
        for (auto& kv : anagram_groups) {
            out.push_back(kv.second);
        }
        
        return out;
    }
#endif
    
    // sort by categorization
    //  - get a unique string for each anagram and group them that way
    //  - supposedly O(N*K) where n is the number of strings and K  is the longest length
    //    but perf is worse because of all the string operations
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram_groups;
        for (auto& s : strs) {
            anagram_groups[anagramString(s)].push_back(s);
        }
            
        vector<vector<string>> out;
        for (auto& kv : anagram_groups) {
            out.push_back(kv.second);
        }
        
        return out;
    }
    
    
private:
    string anagramString(const string& s) {
        int characters[26];
        ::memset(&characters, 0, sizeof characters);
        for (auto c : s) {
            characters[static_cast<size_t>(c - 'a')]++;
        }
        
        stringstream output;
        for (int i = 0; i < sizeof characters / sizeof(int); ++i) {
            output << characters[i] << "#";
        }
        
        return output.str();
    }
};
