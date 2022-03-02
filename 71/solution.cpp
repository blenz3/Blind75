int characterToIdx(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    else 
        return -1; // special case the null terminator
}

struct Node {
    std::array<Node*, 26> nextNodes;
    char val;
    bool isEnd;
    
    Node() 
        : val('\0')
        , isEnd(false)
    {
        nextNodes.fill(nullptr);
    }
    
    Node(char c)
        : val(c)
        , isEnd(false)
    {
        nextNodes.fill(nullptr);
    }
    
    ~Node() {
        for (auto n : nextNodes) {
            delete n;
        }
    }
    
    Node* insertCharacter(char c) {
        int idx = characterToIdx(c);
        if (nextNodes[idx] == nullptr) {
            nextNodes[idx] = new Node(c);
        }
        
        return nextNodes[idx];
    }
    
    void insertWord(const string& s) {
        Node* next = insertCharacter(s[0]);
        for (int i = 1; i < s.length(); ++i) {
            next = next->insertCharacter(s[i]);
        }
        
        next->isEnd = true;
    }
    
    Node* findCharacter(char c) {
        return nextNodes[characterToIdx(c)];
    }
    
    bool findWord(const std::string& s) {
        Node* next = findCharacter(s[0]);
        if (next == nullptr) 
            return false;
        
        for (int i = 1; i < s.length(); ++i) {
            next = next->findCharacter(s[i]);
            if (next == nullptr) {
                return false;
            }
        }
        
        return next->isEnd;
    }
    
    bool findPrefix(const std::string& s ) {
        Node* next = findCharacter(s[0]);
        if (next == nullptr) 
            return false;
        
        for (int i = 1; i < s.length(); ++i) {
            next = next->findCharacter(s[i]);
            if (next == nullptr) {
                return false;
            }
        }
        
        return true;
    }
};


class Trie {
public:
    Trie()
        : tree(new Node())
    {
        
    }
    
    ~Trie() {
        delete tree;
    }
    
    void insert(string word) {
        tree->insertWord(word);
    }
    
    bool search(string word) {
        return tree->findWord(word);
    }
    
    bool startsWith(string prefix) {
        return tree->findPrefix(prefix);
    }

private:
    Node* tree;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
