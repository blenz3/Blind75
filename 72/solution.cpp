int characterToIndex(char c) {
    return c - 'a';
}

struct Node {
    array<Node*, 26> nextNodes;
    bool isEnd;
    char c;
    
    Node()
        : Node('\0')
    {

    }
    
    Node(char character) 
        : nextNodes()
        , isEnd(false)
        , c(character)
    {
        nextNodes.fill(nullptr);
    }
    
    // ~Node() {
    //     for (auto n : nextNodes) {
    //         delete n;
    //     }
    // }
    
    Node* addCharacter(char character) {
        
        int idx = characterToIndex(character);
        Node* next = nextNodes[idx];
        if (next == nullptr) {
            nextNodes[idx] = new Node(character);
            next = nextNodes[idx];
        }
        
        return next;
    }
    
    void addWord(const std::string& s) {
        if (s.empty()) {
            return;
        }
        
        Node* next = addCharacter(s[0]);
        for (int i = 1; i < s.length(); ++i) {
            next = next->addCharacter(s[i]);
        }
        
        next->isEnd = true;
    }    
    
    bool searchWord(const std::string& s) {
        return searchWord(s, 0);
    }
    
private:
    bool searchWord(const std::string& s, int idx) {
        if (idx == s.length()) {
            return isEnd;
        }
        
        // regular letter
        if (s[idx] != '.') {
            // If this is a terminal node we just need to check if it is the end of a word
            // and we are good
            Node* next = nextNodes[characterToIndex(s[idx])];
            if (next == nullptr) {
                return false;
            } else {
                return next->searchWord(s, idx + 1);
            }
        } else {
            // Since this is a magical character just try each in the alphabet to see if any work
            for (auto node : nextNodes) {
                if (node == nullptr) {
                    continue;
                }
                
                if (node->searchWord(s, idx + 1)) 
                    return true;
            }
            
            return false;
        }
    }  
};

class WordDictionary {
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        trie.addWord(word);
    }
    
    bool search(string word) {
        if (word.empty()) return false;
        return trie.searchWord(word);
    }

private:
    Node trie;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
