/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start

/*
class Trie {
public:
    
    unordered_map<char,Trie*> m;
    bool is_string;
    Trie() {
        is_string = false;
    }
    
    void insert(string word) {
        if(word.empty()){
            is_string = true;
            return;
        }
        char c = word.front();
        if(m.count(c)==0)
            m[c] = new Trie();
        m[c]->insert(word.substr(1));
    }
    
    bool search(string word) {
        Trie *p = find(word);
        return p != nullptr && p -> is_string;
    }
    
    
    bool startsWith(string prefix) {
        return find(prefix)!=nullptr;
    }

    Trie* find(string key){
        Trie* node= this;
        for(char c:key){
            if(node->m.count(c))
                node = node->m[c];
            else return nullptr;
        }
        return node;
    }
};
*/


class TrieNode
{
public:
    TrieNode *next[26];
    bool is_word;
    
    // Initialize your data structure here.
    TrieNode(bool b = false)
    {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

class Trie
{
    TrieNode *root;
public:
    Trie()
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s)
    {
        TrieNode *p = root;
        for(int i = 0; i < s.size(); ++ i)
        {
            if(p -> next[s[i] - 'a'] == NULL)
                p -> next[s[i] - 'a'] = new TrieNode();
            p = p -> next[s[i] - 'a'];
        }
        p -> is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string key)
    {
        TrieNode *p = find(key);
        return p != NULL && p -> is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix)
    {
        return find(prefix) != NULL;
    }

private:
    TrieNode* find(string key)
    {
        TrieNode *p = root;
        for(int i = 0; i < key.size() && p != NULL; ++ i)
            p = p -> next[key[i] - 'a'];
        return p;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

