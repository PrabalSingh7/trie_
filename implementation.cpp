#include<iostream>
using namespace std;

class TrieNode  {
    public:
        char data;
        TrieNode *children[26];
        bool isTerminal;
    
        TrieNode(char ch)   {
            data = ch;
            for(int i=0;i<26;i++)
                children[i] = NULL;
            isTerminal = false;
        }
};

class Trie {
public:
    TrieNode *root;
    
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode *root, string word)    {
        
        if(word.length()==0)    {
            root->isTerminal = true;    
            return ;
        }
        
        int index = word[0] - 'a';
        TrieNode *child;
        
        if(root->children[index] != NULL) {       //present
            child = root->children[index];
        }        
        else    {                                 //absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        
        insertUtil(child,word.substr(1));
        
    }
    
    void insert(string word) {
        return insertUtil(root,word);
    }
    
    
    bool searchUtil(TrieNode *root, string word)    {
        
        if(word.length()==0)    {
            return root->isTerminal;
        }
        
        int index = word[0] - 'a';
        TrieNode *child;
        
        if(root->children[index] != NULL) {       //present
            child = root->children[index];
        }        
        else                                     //absent
            return false;
        
        return searchUtil(child,word.substr(1));

    }
    
    bool search(string word) {
        return searchUtil(root,word);
    }
    
    
    bool startsWithUtil(TrieNode *root, string prefix)    {
        
        if(prefix.length()==0)    {
            return true;
        }
        
        int index = prefix[0] - 'a';
        TrieNode *child;
        
        if(root->children[index] != NULL) {       //present
            child = root->children[index];
        }        
        else    {                                 //absent
            return false;
        }
        
        return startsWithUtil(child,prefix.substr(1));
        
    }
    
    bool startsWith(string prefix) {
        return startsWithUtil(root,prefix);
    }
    

    int removeUtil(TrieNode *root, string word)    {

        if(word.length() == 0 && root->isTerminal == true)   {
            root->isTerminal = false;
            return 1;
        }
        if(word.length() == 0 && root->isTerminal == false)   {
            root->isTerminal = false;
            return -1;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if(root->children[index] != NULL)
            child = root->children[index];
        else
            return -1;

        return removeUtil(child,word.substr(1));

    }

    int remove(string word)    {
        return removeUtil(root,word);
    }

};


int main()  {

    Trie *t = new Trie();
    t->insert("abcd");
    t->insert("abcde");
    t->insert("abcdgh");
    t->insert("ab");
    t->insert("abcdefghijklmnopqrstuvwxyz");

    cout<<t->search("abc")<<"\n";
    cout<<t->search("abcde")<<"\n";

    cout<<t->startsWith("abc")<<"\n";
    cout<<t->startsWith("az")<<"\n";

    cout<<t->search("abcde")<<"\n";
    cout<<t->remove("abcde")<<"\n";
    cout<<t->search("abcde")<<"\n";
    cout<<t->remove("a")<<"\n";

    return 0;
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */